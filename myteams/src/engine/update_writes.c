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

int update_write(connection_t *connection)
{
    char buffer[OUT_BUFFER_SIZE];
    int write_size = 0;

    write_size = cb_consume(connection->out, buffer, OUT_BUFFER_SIZE);
    if (write(connection->socketfd, buffer, write_size) < 0)
        return 0;
    printf("[CLIENT%d] -> \"%.*s\"\n",
    connection->socketfd, write_size, buffer);
    return 1;
}

void update_writes(server_t *server, fd_set *writefds)
{
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        int set = FD_ISSET(tmp->connection->socketfd, writefds);
        if (set && update_write(tmp->connection) == 0) {
            printf("[CLIENT%d] Closing connection !\n",
            tmp->connection->socketfd);
            connection_destroy(tmp->connection);
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            free(tmp);
        }
    }
}
