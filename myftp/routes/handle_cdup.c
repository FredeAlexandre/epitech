/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_cdup(client_t *client)
{
    int socket = client->command_socket;
    if (client->is_auth == 0)
        return send_command(socket, REPLY_530, client->session_id);
    char *saved_home = getcwd(NULL, 0);
    chdir(client->pwd);
    if (chdir("..") == -1)
        return send_command(socket, REPLY_550, client->session_id);
    free(client->pwd);
    client->pwd = getcwd(NULL, 0);
    chdir(saved_home);
    free(saved_home);
    send_command(socket, REPLY_200, client->session_id);
}
