/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_pwd(client_t *client)
{
    int s = client->command_socket;
    if (client->is_auth == 0)
        return send_command(s, REPLY_530, client->session_id);
    char buffer[2048] = "\0";
    strcat(buffer, "257 \"");
    strcat(buffer, client->pwd);
    strcat(buffer, "\" created.");
    send_command(s, buffer, client->session_id);
}
