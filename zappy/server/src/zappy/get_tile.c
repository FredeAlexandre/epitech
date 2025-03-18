/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

tile_t *get_tile(int x, int y)
{
    zappy_t *zappy = get_zappy(NULL);
    int index = y * zappy->map->width + x;

    return zappy->map->tiles[index];
}
