/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_help(client_t *client)
{
    send_command(client->command_socket, REPLY_214, client->session_id);
}
