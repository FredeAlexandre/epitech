/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "server.h"

void connection_destroy(connection_t *connection)
{
    if (!connection)
        return;
    cb_destroy(connection->in);
    cb_destroy(connection->out);
    shutdown(connection->socketfd, SHUT_RDWR);
    close(connection->socketfd);
    free(connection);
}
