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

void bct_route(connection_t *connection, char *options)
{
    char *sx = strtok(options, " ");
    if (!sx) {
        send_message(connection, "sbp");
        return;
    }
    int x = atoi(sx);
    char *sy = strtok(NULL, " ");
    if (!sy) {
        send_message(connection, "sbp");
        return;
    }
    int y = atoi(sy);
    bct_compute(connection, x, y);
}

void bct_compute(connection_t *connection, int x, int y)
{
    tile_t *tile = get_tile(x, y);
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "bct %d %d", x, y);
    for (int i = 0; i < ITEMS_AMOUNT; i++) {
        char amount[10];
        sprintf(amount, "%d", get_item_amount(tile, i));
        strcat(buffer, " ");
        strcat(buffer, amount);
    }
    send_message(connection, buffer);
}

