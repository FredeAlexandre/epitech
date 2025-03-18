/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void eject_action(player_t *player)
{
    player->action = NULL;
    send_message(player->client, "ko");
}
