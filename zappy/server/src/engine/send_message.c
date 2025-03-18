/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "server.h"

size_t send_message(connection_t *connection, const char *message)
{
    if (!connection || !message)
        return 0;
    size_t len = strlen(message);
    size_t result = cb_write(connection->out, message, len);
    if (result == len)
        result += cb_write(connection->out, PACKET_END, strlen(PACKET_END));
    return result;
}
