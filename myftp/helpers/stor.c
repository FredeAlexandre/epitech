/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void stor(client_t *client)
{
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *file = strtok(NULL, " ");
    if (file == NULL) {
        send_command(client->command_socket, REPLY_501, client->session_id);
        return free(prompt);
    }
    chdir(client->pwd);
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        send_command(client->command_socket, REPLY_550, client->session_id);
        return free(prompt);
    }
    char buffer[2048];
    int size = 0;
    while ((size = read(client->data_socket, buffer, 2048)) > 0)
        write(fd, buffer, size);
    free(prompt);
}
