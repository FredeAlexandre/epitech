/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#include "server.h"

int set_readfds(server_t *server, fd_set *readfds)
{
    server_node_t *node = server->head;
    int maxfd = server->socketfd;

    FD_ZERO(readfds);
    FD_SET(server->socketfd, readfds);
    while (node) {
        FD_SET(node->connection->socketfd, readfds);
        if (node->connection->socketfd > maxfd)
            maxfd = node->connection->socketfd;
        node = node->next;
    }
    return maxfd;
}
