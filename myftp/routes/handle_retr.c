/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_retr(client_t *client)
{
    int csocket = client->command_socket;
    if (retr_check(client) == -1 || handle_guard(client) == -1)
        return;
    send_command(csocket, REPLY_150, client->session_id);
    int pid = fork();
    if (pid == -1)
        return send_command(csocket, REPLY_550, client->session_id);
    if (pid == 0) {
        retr(client);
        send_command(csocket, REPLY_226, client->session_id);
        shutdown(client->data_socket, SHUT_RDWR);
        close(client->data_socket);
        close(client->root_socket);
        exit(0);
    } else {
        client->data_type = DATA_NONE;
        client->data_socket = 0;
        client->root_socket = 0;
    }
}
