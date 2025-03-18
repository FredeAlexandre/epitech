/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "zappy.h"

void quit_route(connection_t *connection)
{
    connection->delete = 1;
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "bye bye :)");
    send_message(connection, buffer);
}
