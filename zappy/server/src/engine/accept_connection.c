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
#include "log.h"

void accept_connection_push(server_t *server, server_node_t *node)
{
    if (!server->head) {
        server->head = node;
        server->tail = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        server->tail->next = node;
        node->prev = server->tail;
        node->next = NULL;
        server->tail = node;
    }
}

void accept_connection(server_t *server)
{
    connection_t *connection = connection_init(server->socketfd);
    if (!connection) return;
    server_node_t *node = malloc(sizeof(server_node_t));
    if (!node) {
        connection_destroy(connection);
        return;
    }
    node->connection = connection;
    accept_connection_push(server, node);
    if (SERVER_CONNECTIONS_LOG)
        printf("[SERVER] New connection at: %d !\n", connection->socketfd);
}
