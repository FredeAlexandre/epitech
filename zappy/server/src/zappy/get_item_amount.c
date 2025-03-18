/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

int get_item_amount(tile_t *tile, Item item)
{
    int amount = 0;

    for (int i = 0; i < tile->items_amount; i++)
        if (tile->items[i] == item)
            amount++;
    return amount;
}
