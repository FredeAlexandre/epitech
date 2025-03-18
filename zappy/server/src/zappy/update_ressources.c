/*
** EPITECH PROJECT, 2022
** update_zappy.c
** File description:
** All functions used by the server
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "zappy.h"

int must_update(void)
{
    zappy_t *zappy = get_zappy(NULL);
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    long timeout = 20 * TIME_UNIT / zappy->freq;
    long ellapsed = (now.tv_sec - zappy->map->last_ressources_spawn.tv_sec) * TIME_UNIT + (now.tv_nsec - zappy->map->last_ressources_spawn.tv_nsec);
    if (zappy->map->first_spawned == 1 && ellapsed < timeout) return 0;
    zappy->map->first_spawned = 1;
    zappy->map->last_ressources_spawn = now;
    return 1;
}

struct density_s {
    enum Item_e item;
    int density;
};

struct density_s density[] = {
    { Food, 500 },
    { Linemate, 30 },
    { Deraumere, 15 },
    { Sibur, 10 },
    { Mendiane, 10 },
    { Phiras, 8 },
    { Thystame, 5 }
};


void update_ressources(void)
{
    zappy_t *zappy = get_zappy(NULL);
    if (!must_update()) return;

    for (int i = 0; i < ITEMS_AMOUNT; i++) {
        enum Item_e item = density[i].item;
        int actual_amount = get_total_item_amount(item);
        int max_amount = (zappy->map->width * zappy->map->height * density[i].density) / 100;
        if (actual_amount >= max_amount) continue;
        int x = rand() % zappy->map->width;
        int y = rand() % zappy->map->height;
        tile_t *tile = get_tile(x, y);
        add_item(tile, item);
    }
}
