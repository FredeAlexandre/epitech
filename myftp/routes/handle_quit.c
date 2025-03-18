/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_quit(client_t *client)
{
    int socket = client->command_socket;
    send_command(socket, REPLY_221, client->session_id);
    shutdown(socket, SHUT_RDWR);
    close(socket);
    client->command_socket = 0;
}
