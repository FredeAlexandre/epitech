/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int check_credentials(char *username, char *password)
{
    if (strcmp(username, "Anonymous") == 0) {
        if (strlen(password) == 0) {
            return 1;
        }
    }
    return 0;
}

void handle_pass(client_t *client)
{
    char *prompt = strdup(client->command);
    char *password;
    if (strcmp(prompt, "PASS ") == 0) {
        password = "";
    } else {
        strtok(prompt, " ");
        password = strtok(NULL, " ");
    }
    int socket = client->command_socket;
    if (password == NULL)
        return send_command(socket, REPLY_501, client->session_id);
    if (client->password != NULL) free(client->password);
    client->password = strdup(password);
    if (check_credentials(client->username, client->password)) {
        client->is_auth = 1;
        send_command(socket, REPLY_230, client->session_id);
    } else {
        send_command(socket, REPLY_530, client->session_id);
    }
    free(prompt);
}
