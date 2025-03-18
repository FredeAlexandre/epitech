/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"
#include "log.h"

int remove_item(tile_t *tile, Item item)
{
    int index = -1;
    for (int i = 0; i < tile->items_amount; i++) {
        if (tile->items[i] == item) {
            index = i;
            break;
        }
    }

    if (index == -1) return -1;

    tile->items_amount--;
    tile->items[index] = tile->items[tile->items_amount];
    if (ZAPPY_RESSOURCES_LOG)
        printf("[ZAPPY] Item |%s| added at x: %i, y: %i\n", get_item_name(item), tile->x, tile->y);
    return 0;
}
