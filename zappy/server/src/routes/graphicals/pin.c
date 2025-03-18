/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <string.h>

#include "zappy.h"

void pin_route(connection_t *connection, char *options)
{
    zappy_t *zappy = get_zappy(NULL);
    int player_id = atoi(options);

    team_t *team = zappy->teams;

    while (team) {
        player_t *player = team->players;
        while (player) {
            if (player->id == player_id) {
                char buffer[OUT_BUFFER_SIZE];
                sprintf(buffer, "pin %d %d %d", player->id, player->x, player->y);
                for (int i = 0; i < ITEMS_AMOUNT; i++) {
                    char amount[10];
                    sprintf(amount, "%d", get_amount_inventory(player, i));
                    strcat(buffer, " ");
                    strcat(buffer, amount);
                }
                send_message(connection, buffer);
                return;
            }
            player_t *player = player->next;
        }
        team = team->next;
    }
}
