/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_user(client_t *client)
{
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *username = strtok(NULL, " ");
    int socket = client->command_socket;
    if (username == NULL)
        return send_command(socket, REPLY_501, client->session_id);
    if (client->username != NULL) free(client->username);
    client->username = strdup(username);
    send_command(socket, REPLY_331, client->session_id);
    free(prompt);
}
