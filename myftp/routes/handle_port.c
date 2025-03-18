/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int get_ip(client_t *client, struct sockaddr_in *address)
{
    int csocket = client->command_socket;
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *ip = strtok(NULL, " ");
    if (ip == NULL) {
        send_command(csocket, REPLY_501, client->session_id);
        free(prompt);
        return -1;
    }
    extract_ip(ip, address);
    free(prompt);
    return 0;
}

void handle_port(client_t *client)
{
    int csocket = client->command_socket;
    if (client->is_auth == 0)
        return send_command(csocket, REPLY_530, client->session_id);
    if (get_ip(client, &client->client) == -1)
        return send_command(csocket, REPLY_501, client->session_id);
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1)
        return send_command(csocket, REPLY_550, client->session_id);
    client->data_socket = socketfd;
    client->data_type = DATA_ACTIVE;
    send_command(csocket, REPLY_200, client->session_id);
}
