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

void update_server(void)
{
    server_t *server = get_server(NULL);
    fd_set readfds;
    fd_set writefds;
    struct timeval tv = {0, 0};
    int maxfd = set_readfds(server, &readfds);

    if (select(maxfd + 1, &readfds, NULL, NULL, &tv) == -1) {
        if (errno == EINTR) return;
        perror("[SERVER] Select reads failed");
    }
    if (FD_ISSET(server->socketfd, &readfds))
        accept_connection(server);
    update_reads(server, &readfds);
    maxfd = set_writefds(server, &writefds);
    if (select(maxfd + 1, NULL, &writefds, NULL, &tv) == -1) {
        if (errno == EINTR) return;
        perror("[SERVER] Select writes failed");
    }
    update_writes(server, &writefds);
    clean_connections(server);
}
