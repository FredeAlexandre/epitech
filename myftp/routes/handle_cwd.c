/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_cwd(client_t *client)
{
    int socket = client->command_socket;
    if (client->is_auth == 0)
        return send_command(socket, REPLY_530, client->session_id);
    char *saved_home = getcwd(NULL, 0);
    chdir(client->pwd);
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *new_path = strtok(NULL, " ");
    if (new_path == NULL)
        return send_command(socket, REPLY_550, client->session_id);
    if (chdir(new_path) == -1)
        return send_command(socket, REPLY_550, client->session_id);
    free(client->pwd);
    client->pwd = getcwd(NULL, 0);
    chdir(saved_home);
    free(prompt);
    free(saved_home);
    send_command(socket, REPLY_250, client->session_id);
}
