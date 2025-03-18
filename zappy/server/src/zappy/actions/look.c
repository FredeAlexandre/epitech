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

int look_action_dx(enum Direction_e direction, int d, int s)
{
    switch (direction)
    {
        case North:
            return s;
        case South:
            return -s;
        case East:
            return d;
        case West:
            return -d;
    }
    return 0;
}

int look_action_dy(enum Direction_e direction, int d, int s)
{
    switch (direction)
    {
        case North:
            return -d;
        case South:
            return d;
        case East:
            return s;
        case West:
            return -s;
    }
    return 0;
}

void look_action(player_t *player)
{
    if (!player->client) return;
    player->action = NULL;
    char result[OUT_BUFFER_SIZE];
    bzero(result, OUT_BUFFER_SIZE);
    zappy_t *zappy = get_zappy(NULL);

    enum Direction_e direction = player->direction;

    strcat(result, "[");

    for (int d = 0; d <= player->level; d++) {
        for (int s = -d; s <= d; s++) {
            int x = (player->x + look_action_dx(direction, d, s)) % zappy->map->width;
            int y = (player->y + look_action_dy(direction, d, s)) % zappy->map->height;
            tile_t *tile = get_tile(x, y);
            for (int i = 0; i < tile->players_amount; i++) {
                strcat(result, " player");
            }
            for (int i = 0; i < tile->items_amount; i++) {
                strcat(result, " ");
                strcat(result, get_item_name(tile->items[i]));
            }
            strcat(result, ",");
        }
    }
    result[strlen(result) - 1] = ']';
    send_message(player->client, result);
}
