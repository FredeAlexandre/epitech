/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server.h"

void destroy_server(void)
{
    server_t *server = get_server(NULL);
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        connection_destroy(tmp->connection);
        free(tmp);
    }
    shutdown(server->socketfd, SHUT_RDWR);
    close(server->socketfd);
    free(server);
    printf("[SERVER] Bye bye :)\n");
}
