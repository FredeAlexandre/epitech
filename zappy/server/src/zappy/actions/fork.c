/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void fork_action(player_t *player)
{
    char buffer[OUT_BUFFER_SIZE];
    player_t *egg = add_player(get_team_of(player), player->x, player->y, 1);
    sprintf(buffer, "enw %d %d %d %d", egg->id, player->id, player->x, player->y);
    graphic_broadcast(buffer);
    player->action = NULL;
    send_message(player->client, "ok");
}
