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
#include <string.h>

#include "server.h"

void check_routes(connection_t *connection)
{
    send_message(connection, "Wow unkwown command");
}

void router(void)
{
    server_t *server = get_server(NULL);
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;

        char command[MAX_COMMAND_SIZE];

        int result = recv_message(tmp->connection, command, MAX_COMMAND_SIZE);
        if (result == 0) continue;
        request_parser(command);
        check_routes(tmp->connection);
    }
}
