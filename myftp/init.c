/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Initialisation function
*/

#include "myftp.h"

int create_socket(char *port)
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    int iport = atoi(port);

    if (iport == 0) {
        fprintf(stderr, "Error: Invalid port\n");
        exit(84);
    }
    if (socket_fd == -1)
        return -1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(iport);
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        return -1;
    if (listen(socket_fd, LISTEN_QUEUE) < 0)
        return -1;
    return socket_fd;
}

void init(int argc, char *const *const argv, list_t **clients, int *main_socket)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ./myftp port path\n");
        exit(84);
    }
    *main_socket = create_socket(argv[1]);
    if (*main_socket == -1) {
        fprintf(stderr, "Error: Can't create socket\n");
        exit(84);
    }
    if (chdir(argv[2]) == -1) {
        fprintf(stderr, "Error: Can't change directory\n");
        exit(84);
    }
    *clients = list_create();
    printf(SERVER_PREFIX "Server started on port %s\n", argv[1]);
}
