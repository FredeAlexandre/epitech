/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "zappy.h"

void destroy_players(player_t *players)
{
    player_t *actual = players;
    player_t *next;

    while (actual) {
        next = actual->next;
        connection_t *connection = actual->client;
        if (connection) connection->player = NULL;
        free(actual);
        actual = next;
    }
}

void destroy_teams(team_t *teams)
{
    team_t *actual = teams;
    team_t *next;

    while (actual) {
        next = actual->next;
        destroy_players(actual->players);
        free(actual);
        actual = next;
    }
}

void destroy_map(map_t *map)
{
    int count = map->width * map->height;
    for (int i = 0; i < count; i++) {
        if (map->tiles[i]->items_amount > 0)
            free(map->tiles[i]->items);
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}

void destroy_zappy(void)
{
    zappy_t *zappy = get_zappy(NULL);
    destroy_teams(zappy->teams);
    destroy_map(zappy->map);
    free(zappy);
    destroy_server();
}
