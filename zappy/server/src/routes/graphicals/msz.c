/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "zappy.h"

void msz_route(connection_t *connection)
{
    zappy_t *zappy = get_zappy(NULL);
    int width = zappy->map->width;
    int height = zappy->map->height;
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "msz %d %d", width, height);
    send_message(connection, buffer);
}
