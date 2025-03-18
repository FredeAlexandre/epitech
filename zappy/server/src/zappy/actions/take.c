/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

void take_action(player_t *player)
{
    Item item = get_item_by_name(player->options);
    free(player->options);
    player->options = NULL;
    tile_t *tile = get_tile(player->x, player->y);
    player->action = NULL;
    int removed = remove_item(tile, item);
    if (removed == 0) {
        int amount = get_amount_inventory(player, item);
        set_amount_inventory(player, item, amount + 1);
        char buffer[OUT_BUFFER_SIZE];
        sprintf(buffer, "pgt %d %d", player->id, item);
        graphic_broadcast(buffer);
    }
    if (player->client) send_message(player->client, removed == 0 ? "ok" : "ko");
}
