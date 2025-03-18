/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "server.h"

connection_t *connection_init(int socketfd)
{
    connection_t *connection = malloc(sizeof(connection_t));
    if (!connection) return NULL;
    connection->socketfd = accept(socketfd, NULL, NULL);
    if (connection->socketfd == -1) {
        free(connection);
        return NULL;
    }
    connection->in = cb_create(IN_BUFFER_SIZE);
    if (!connection->in) {
        free(connection);
        return NULL;
    }
    connection->out = cb_create(OUT_BUFFER_SIZE);
    if (!connection->out) {
        cb_destroy(connection->in);
        free(connection);
        return NULL;
    }
    connection->delete = 0;
    return connection;
}
