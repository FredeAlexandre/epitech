/*
** EPITECH PROJECT, 2022
** update_zappy.c
** File description:
** All functions used by the server
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "server.h"
#include "zappy.h"

void kill_player(player_t *player)
{
    team_t *team = get_team_of(player);
    zappy_t *zappy = get_zappy(NULL);
    if (!team) return;
    player_t *actual = team->players;
    player_t *prev = NULL;
    
    printf("[ZAPPY] Killing player [%i] from {%s}\n", player->id, team->name);
    if (player->client) send_message(player->client, "dead");
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "pdi %d", player->id);
    graphic_broadcast(buffer);
    if (player->client) ((connection_t *)player->client)->delete = 1;

    if (actual->id == player->id) {
        team->players = actual->next;
        free(actual);
        add_player(team, rand() % zappy->map->width, rand() % zappy->map->height, 0);
        return;
    }
    while (actual) {
        if (actual->id == player->id) {
            prev->next = actual->next;
            free(actual);
            add_player(team, rand() % zappy->map->width, rand() % zappy->map->height, 0);
            return;
        }
        prev = actual;
        actual = actual->next;
    }
}

int player_eat(player_t *player)
{
    if (player->inventory.food <= 0) return 0;
    zappy_t *zappy = get_zappy(NULL);
    player->inventory.food--;
    clock_gettime(CLOCK_MONOTONIC, &player->dead_timeout);
    long timeout = LIFE_UNIT * 1L / zappy->freq;
    int seconds = timeout / TIME_UNIT;
    int nanoseconds = timeout % TIME_UNIT;
    player->dead_timeout.tv_sec += seconds;
    player->dead_timeout.tv_nsec += nanoseconds;
    return 1;
}

int eat_or_kill(player_t *player)
{
    if (player_eat(player))
        return 1;
    kill_player(player);
    return 0;
}

int update_player_timeout(player_t *player)
{
    if (player->dead_timeout.tv_sec == 0 && player->dead_timeout.tv_nsec == 0) {
        printf("[ZAPPY] New player connection to [%i]\n", player->id);
        char buffer[OUT_BUFFER_SIZE];
        if (player->is_egg) {
            sprintf(buffer, "ebo %d", player->id);
            graphic_broadcast(buffer);
            player->is_egg = 0;
        } else {
            sprintf(buffer, "pnw %d %d %d %d %d %s", player->id, player->x, player->y, player->direction + 1, player->level, get_team_of(player)->name);
            graphic_broadcast(buffer);
        }
        player->inventory.food = 10;
        player_eat(player);
    } else {
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        if (now.tv_sec > player->dead_timeout.tv_sec)
            return eat_or_kill(player);
        if (now.tv_sec == player->dead_timeout.tv_sec && now.tv_nsec > player->dead_timeout.tv_nsec)
            return eat_or_kill(player);
    }
    return 1;
}

void update_player(player_t *player)
{
    int alive = update_player_timeout(player);
    if (!alive || player->action == NULL) return;
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    if (now.tv_sec < player->action_timeout.tv_sec) return;
    if (now.tv_sec == player->action_timeout.tv_sec && now.tv_nsec < player->action_timeout.tv_nsec) return;
    player->action(player);
}

void update_players(void)
{
    zappy_t *zappy = get_zappy(NULL);

    team_t *actual_team = zappy->teams;
    while (actual_team) {
        player_t *actual_player = actual_team->players;
        player_t *next_player = actual_player->next;
        while (actual_player) {
            if (actual_player->client != NULL) update_player(actual_player);
            if (next_player == NULL) break;
            actual_player = next_player;
            next_player = next_player->next;
        }
        actual_team = actual_team->next;
    }
}
