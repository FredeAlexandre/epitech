/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void right_action(player_t *player)
{
    player->direction = (player->direction + 1) % 4;
    player->action = NULL;
    if (player->client) send_message(player->client, "ok");
}
