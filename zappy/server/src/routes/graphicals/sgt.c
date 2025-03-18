/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "zappy.h"

void sgt_route(connection_t *connection)
{
    zappy_t *zappy = get_zappy(NULL);
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "sgt %ld", zappy->freq);
    send_message(connection, buffer);
}
