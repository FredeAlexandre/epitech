/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#include "server.h"

int update_read(connection_t *connection)
{
    char buffer[IN_BUFFER_SIZE];
    int read_size = 0;

    read_size = read(connection->socketfd, buffer, IN_BUFFER_SIZE);
    if (read_size <= 0) return 0;
    cb_write(connection->in, buffer, read_size);
    printf("[CLIENT%d] <- \"%.*s\"\n", connection->socketfd, read_size, buffer);
    return 1;
}

void update_read_delete(server_t *server, server_node_t *tmp)
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

void update_reads(server_t *server, fd_set *readfds)
{
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        int set = FD_ISSET(tmp->connection->socketfd, readfds);
        if (set && update_read(tmp->connection) == 0) {
            update_read_delete(server, tmp);
        }
    }
}
