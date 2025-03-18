/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#include "server.h"

void graphic_broadcast(const char *message)
{
    server_t *server = get_server(NULL);

    server_node_t *node = server->head;

    while (node) {
        if (node->connection->player == (void *)IS_GRAPHIC)
            send_message(node->connection, message);
        node = node->next;
    }
}
