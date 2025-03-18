/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "zappy.h"

void tna_route(connection_t *connection)
{
    zappy_t *zappy = get_zappy(NULL);
    
    team_t *team = zappy->teams;

    while (team) {
        char buffer[OUT_BUFFER_SIZE];
        sprintf(buffer, "tna %s", team->name);
        send_message(connection, buffer);
        team = team->next;
    }
}
