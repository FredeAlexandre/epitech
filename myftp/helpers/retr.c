/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int retr_check(client_t *client)
{
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *file = strtok(NULL, " ");
    if (file == NULL) {
        send_command(client->command_socket, REPLY_501, client->session_id);
        free(prompt);
        return -1;
    }
    char *save = getcwd(NULL, 0);
    chdir(client->pwd);
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        send_command(client->command_socket, REPLY_550, client->session_id);
        free(prompt);
        chdir(save);
        free(save);
        return -1;
    }
    chdir(save);
    free(save);
    free(prompt);
    return 0;
}

void retr(client_t *client)
{
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *file = strtok(NULL, " ");
    if (file == NULL) {
        send_command(client->command_socket, REPLY_501, client->session_id);
        return free(prompt);
    }
    chdir(client->pwd);
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        send_command(client->command_socket, REPLY_550, client->session_id);
        return free(prompt);
    }
    char buffer[2048];
    int size = 0;
    while ((size = read(fd, buffer, 2048)) > 0)
        write(client->data_socket, buffer, size);
    free(prompt);
}
