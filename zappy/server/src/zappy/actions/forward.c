/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void forward_action(player_t *player)
{

    printf("[ZAPPY] Forward to %i of [%i], from x: %i, y: %i ", player->direction, player->id, player->x, player->y);
    get_tile(player->x, player->y)->players_amount--;
    switch (player->direction)
    {
        case North:
            player->y--;
            if (player->y < 0) player->y = get_zappy(NULL)->map->height - 1;
            break;
        
        case East:
            player->x++;
            if (player->x >= get_zappy(NULL)->map->width) player->x = 0;
            break;
        
        case South:
            player->y++;
            if (player->y >= get_zappy(NULL)->map->height) player->y = 0;
            break;
        
        case West:
            player->x--;
            if (player->x < 0) player->x = get_zappy(NULL)->map->width - 1;
            break;
    }
    get_tile(player->x, player->y)->players_amount++;
    player->action = NULL;
    printf("to x: %i, y: %i\n", player->x, player->y);
    if (player->client) send_message(player->client, "ok");
}
