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

void delete_connection(server_node_t *tmp, server_t *server)
{
    printf("[CLIENT%d] Closing connection !\n", tmp->connection->socketfd);
    connection_destroy(tmp->connection);
    server_node_t *next = tmp->next;
    server_node_t *prev = tmp->prev;
    if (next) next->prev = prev;
    if (prev) prev->next = next;
    if (tmp == server->head)
        server->head = next;
    if (tmp == server->tail)
        server->tail = prev;
    free(tmp);
}

void clean_connections(server_t *server)
{
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        if (tmp->connection->delete == 1) {
            delete_connection(tmp, server);
        }
    }
}
