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

int set_writefds(server_t *server, fd_set *writefds)
{
    server_node_t *node = server->head;
    int maxfd = 0;

    FD_ZERO(writefds);
    while (node) {
        if (node->connection->out->empty == 1) {
            node = node->next;
            continue;
        }
        FD_SET(node->connection->socketfd, writefds);
        if (node->connection->socketfd > maxfd)
            maxfd = node->connection->socketfd;
        node = node->next;
    }
    return maxfd;
}
