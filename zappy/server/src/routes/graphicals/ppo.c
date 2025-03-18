/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "zappy.h"

void ppo_route(connection_t *connection, char *options)
{
    zappy_t *zappy = get_zappy(NULL);
    int player_id = atoi(options);

    team_t *team = zappy->teams;

    while (team) {
        player_t *player = team->players;
        while (player) {
            if (player->id == player_id) {
                char buffer[OUT_BUFFER_SIZE];
                sprintf(buffer, "ppo %d %d %d %d", player->id, player->x, player->y, player->direction + 1);
                send_message(connection, buffer);
                return;
            }
            player_t *player = player->next;
        }
        team = team->next;
    }
}
