/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void connect_nbr_action(player_t *player)
{
    if (!player->client) return;
    int slots = 0;
    team_t *team = get_team_of(player);
    if (!team) return;
    player_t *actual = team->players;
    while (actual) {
        if (actual->client == NULL) slots++;
        actual = actual->next;
    }
    player->action = NULL;
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "%d", slots);
    send_message(player->client, buffer);
}
