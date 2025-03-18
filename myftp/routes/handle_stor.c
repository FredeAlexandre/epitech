/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

/*

#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../myftp.h"

int store_file_guard(char *file)
{
    if (is_logged(-1) != 2) {
        cwrite(get_command_socket(0), "530 Not logged in.\r\n");
        return -1;
    }
    if (file == NULL) {
        cwrite(get_command_socket(0), REPLY_501);
        return -1;
    }
    return 0;
}

void store_file_child(char *file)
{
    cwrite(get_command_socket(0), REPLY_150);
    int socketfd = please_connnect();
    if (socketfd == -1) raise(SIGINT);
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (void)cwrite(get_command_socket(0), REPLY_550);
    char buffer[2048];
    int size = 0;
    while ((size = read(socketfd, buffer, 2048)) > 0)
        write(fd, buffer, size);
    close(fd);
    close(socketfd);
    cwrite(get_command_socket(0), "226 Closing data connection.\r\n");
    raise(SIGINT);
}

void store_file(void)
{
    char *file = strtok(NULL, " ");
    if (store_file_guard(file) == -1) return;
    int pid = fork();
    if (pid < 0) cerror("Error fork");
    if (pid == 0) {
        store_file_child(file);
    } else {
        list_int_add(get_children(), pid);
        reset_data_socket();
    }
}
*/

void handle_stor(client_t *client)
{
    int csocket = client->command_socket;
    if (handle_guard(client) == -1)
        return;
    send_command(csocket, REPLY_150, client->session_id);
    int pid = fork();
    if (pid == -1)
        return send_command(csocket, REPLY_550, client->session_id);
    if (pid == 0) {
        stor(client);
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
