/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

void handle_type(client_t *client)
{
    int s = client->command_socket;
    if (client->is_auth == 0)
        return send_command(s, REPLY_530, client->session_id);
    char *prompt = strdup(client->command);
    strtok(prompt, " ");
    char *type = strtok(NULL, " ");
    if (type == NULL) {
        free(prompt);
        return send_command(s, REPLY_501, client->session_id);
    }
    if (strcmp(type, "A") == 0) {
        return send_command(s, REPLY_200, client->session_id);
    } else if (strcmp(type, "I") == 0) {
        return send_command(s, REPLY_200, client->session_id);
    } else {
        send_command(s, REPLY_504, client->session_id);
    }
    free(prompt);
}
