/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server.h"
#include "zappy.h"

int create_server(server_t *server, int port)
{
    struct sockaddr_in adrr;
    server->socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socketfd == -1) {
        free(server);
        return -1;
    }
    adrr.sin_family = AF_INET;
    adrr.sin_addr.s_addr = INADDR_ANY;
    adrr.sin_port = htons(port);

    if (bind(server->socketfd, (struct sockaddr *)&adrr, sizeof(adrr)) == -1) {
        free(server);
        return -1;
    }
    if (listen(server->socketfd, QUEU_SIZE) == -1) {
        free(server);
        return -1;
    }
    return 0;
}

int get_port(int sockfd)
{
    struct sockaddr_in my_addr;
    socklen_t len = sizeof(my_addr);
    getsockname(sockfd, (struct sockaddr *) &my_addr, &len);
    return ntohs(my_addr.sin_port);
}

int init_server(int port)
{
    if (port < 0) return -1;
    server_t *server = malloc(sizeof(server_t));
    if (!server) {
        return -1;
    }
    if (create_server(server, port) < 0) {
        printf("[SERVER] Error while trying to connect to port %d\n", port);
        return -1;
    }
    printf("[SERVER] Initializing server on port %d\n", get_port(server->socketfd));
    server->head = NULL;
    server->tail = NULL;
    get_server(server);
    return 0;
}
