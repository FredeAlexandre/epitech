/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

int get_total_item_amount(Item item)
{
    zappy_t *zappy = get_zappy(NULL);
    int amount = 0;

    int count = zappy->map->height * zappy->map->width;

    for (int i = 0; i < count; i++) {
        amount += get_item_amount(zappy->map->tiles[i], item);
    }

    return amount;
}
