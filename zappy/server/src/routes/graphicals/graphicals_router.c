/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <strings.h>

#include "zappy.h"

void graphicals_router(connection_t *connection, char *command)
{
    if (strncmp(command, "msz", 3) == 0) return msz_route(connection);
    if (strncmp(command, "quit", 4) == 0) return quit_route(connection);
    if (strncmp(command, "bct", 3) == 0) return bct_route(connection, command + 4);
    if (strncmp(command, "mct", 3) == 0) return mct_route(connection);
    if (strncmp(command, "tna", 3) == 0) return tna_route(connection);
    if (strncmp(command, "ppo", 3) == 0) return ppo_route(connection, command + 4);
    if (strncmp(command, "plv", 3) == 0) return plv_route(connection, command + 4);
    if (strncmp(command, "pin", 3) == 0) return pin_route(connection, command + 4);
    send_message(connection, "suc");
}
