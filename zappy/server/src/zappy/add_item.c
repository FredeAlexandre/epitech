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

void add_item(tile_t *tile, Item item)
{
    int index = tile->items_amount;

    tile->items_amount++;
    tile->items = realloc(tile->items, sizeof(Item) * tile->items_amount);
    tile->items[index] = item;
    if (!ZAPPY_RESSOURCES_LOG) return;
    printf("[ZAPPY] Item |%s| added at x: %i, y: %i\n", get_item_name(item), tile->x, tile->y);
}
