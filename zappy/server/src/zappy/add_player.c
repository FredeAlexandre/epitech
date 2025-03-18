/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "zappy.h"

int get_player_id(void)
{
    static int id = 0;

    id++;

    return id;
}

player_t *add_player(team_t *team, int x, int y, int is_egg)
{
    player_t *new_player = malloc(sizeof(player_t));
    player_t *actual = team->players;

    if (!new_player) return NULL;
    bzero(new_player, sizeof(player_t));
    new_player->id = get_player_id();
    new_player->x = x;
    new_player->y = y;
    new_player->level = 1;
    new_player->direction = rand() % 4;
    new_player->is_egg = is_egg;
    printf("[ZAPPY] New player [%i] added to team {%s}\n", new_player->id, team->name);
    if (!actual) {
        team->players = new_player;
        return new_player;
    }
    while (actual->next) actual = actual->next;
    actual->next = new_player;
    return new_player;
}
