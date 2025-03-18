/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "myftp.h"

int is_command_finished(char *s)
{
    int len = strlen(s);
    if (len < 2) return 0;
    if (s[len - 2] == '\r' && s[len - 1] == '\n') return 1;
    return 0;
}

int has_command(client_t *client)
{
    char buffer[READ_BUFFER];
    int read_size = read(client->command_socket, buffer, READ_BUFFER);
    if (read_size <= 0) return -1;
    buffer[read_size] = '\0';
    int len = read_size;
    if (client->command == NULL) {
        client->command = malloc(sizeof(char) * (len + 1));
        strcpy(client->command, buffer);
    } else {
        len += strlen(client->command);
        client->command = realloc(client->command, sizeof(char) * (len + 1));
        strcat(client->command, buffer);
    }
    if (is_command_finished(client->command)) {
        client->command[strlen(client->command) - 2] = '\0';
        return 1;
    } else {
        return 0;
    }
}

void clean_command(client_t *client)
{
    free(client->command);
    client->command = NULL;
}

int handle_command(client_t *client)
{
    int result = has_command(client);
    if (result != 1) return result;
    printf("[SESSION %d] <- \"%s\"\n", client->session_id, client->command);
    router(client);
    clean_command(client);
    return result;
}
