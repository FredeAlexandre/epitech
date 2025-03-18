/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_list_update_dir(client_t *client)
{
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *dir = strtok(NULL, " ");
    if (dir == NULL) return free(prompt);
    if (chdir(dir) < 0) {
        return free(prompt);
    }
    free(client->pwd);
    client->pwd = getcwd(NULL, 0);
    free(prompt);
}

void handle_list(client_t *client)
{
    int csocket = client->command_socket;
    if (handle_guard(client) == -1)
        return;
    send_command(csocket, REPLY_150, client->session_id);
    int pid = fork();
    if (pid == -1)
        return send_command(csocket, REPLY_550, client->session_id);
    if (pid == 0) {
        handle_list_update_dir(client);
        show_files(client);
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
