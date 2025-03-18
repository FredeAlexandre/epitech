/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_noop(client_t *client)
{
    int s = client->command_socket;
    if (client->is_auth == 0)
        return send_command(s, REPLY_530, client->session_id);
    return send_command(s, REPLY_200, client->session_id);
}
