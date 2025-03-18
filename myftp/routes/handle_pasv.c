/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int get_random_socket(int *fsocketfd, int *fport)
{
    int port = 1024;
    struct sockaddr_in address;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) return -1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    while (bind(socketfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        if (port > 65535)
            return -1;
        address.sin_port = htons(++port);
    }
    if (listen(socketfd, 1) == -1)
        return -1;
    *fsocketfd = socketfd;
    *fport = port;
    return 0;
}

void handle_pasv(client_t *client)
{
    int csocket = client->command_socket;
    if (client->is_auth == 0)
        return send_command(csocket, REPLY_530, client->session_id);
    int socketfd = 0;
    int port = 0;
    char result[128] = "\0";
    if (get_random_socket(&socketfd, &port) == -1)
        return send_command(csocket, REPLY_550, client->session_id);
    struct sockaddr_in pub_addr;
    socklen_t len = sizeof(pub_addr);
    getsockname(csocket, (struct sockaddr *)&pub_addr, &len);
    get_227(ntohl(pub_addr.sin_addr.s_addr), port, result);
    send_command(csocket, result, client->session_id);
    client->root_socket = socketfd;
    client->data_type = DATA_PASSIVE;
}
