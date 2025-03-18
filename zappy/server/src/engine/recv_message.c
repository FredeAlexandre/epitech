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

size_t recv_message(connection_t *connection, char *buffer, size_t size)
{
    if (!connection || !buffer || size == 0)
        return 0;
    return cb_getline(connection->in, PACKET_END, buffer, size);
}
