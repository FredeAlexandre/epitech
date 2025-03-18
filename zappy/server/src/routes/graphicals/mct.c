/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "zappy.h"

void mct_route(connection_t *connection)
{
    zappy_t *zappy = get_zappy(NULL);
    
    for (int y = 0; y < zappy->map->height; y++) {
        for (int x = 0; x < zappy->map->width; x++) {
            bct_compute(connection, x, y);
        }
    }
}
