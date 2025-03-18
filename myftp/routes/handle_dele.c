/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int can_delete(char *file, uid_t uid, gid_t gid)
{
    struct stat statbuf;
    if (stat(file, &statbuf) == -1)
        return 0;
    if (!S_ISREG(statbuf.st_mode))
        return 0;
    if (uid == 0)
        return 1;
    if (uid == statbuf.st_uid)
        return (statbuf.st_mode & S_IWUSR) ? 1 : 0;
    if (gid == statbuf.st_gid)
        return (statbuf.st_mode & S_IWGRP) ? 1 : 0;
    return (statbuf.st_mode & S_IWOTH) ? 1 : 0;
}

void handle_dele(client_t *client)
{
    int socket = client->command_socket;
    if (client->is_auth == 0)
        return send_command(socket, REPLY_530, client->session_id);
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *path = strtok(NULL, " ");
    if (path == NULL)
        return send_command(socket, REPLY_501, client->session_id);
    char *save = getcwd(NULL, 0);
    chdir(client->pwd);
    if (can_delete(path, getuid(), getgid()) && unlink(path) != -1) {
        send_command(socket, REPLY_250, client->session_id);
    } else {
        send_command(socket, REPLY_550, client->session_id);
    }
    chdir(save);
    free(save);
}
