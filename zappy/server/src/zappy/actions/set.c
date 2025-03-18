/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void set_action(player_t *player)
{
    Item item = get_item_by_name(player->options);
    free(player->options);
    player->options = NULL;
    tile_t *tile = get_tile(player->x, player->y);
    player->action = NULL;

    int hold = get_amount_inventory(player, item);

    if (hold > 0) {
        set_amount_inventory(player, item, hold - 1);
        add_item(tile, item);
        char buffer[OUT_BUFFER_SIZE];
        sprintf(buffer, "pdr %d %d", player->id, item);
        graphic_broadcast(buffer);
    }
    if (player->client) send_message(player->client, hold > 0 ? "ok" : "ko");
}
