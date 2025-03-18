/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "myftp.h"

void basic_routes(client_t *client, int *n)
{
    *n = 0;
    if (strncmp(client->command, "USER", 4) == 0) return handle_user(client);
    if (strncmp(client->command, "PASS", 4) == 0) return handle_pass(client);
    if (strncmp(client->command, "CWD", 3) == 0) return handle_cwd(client);
    if (strncmp(client->command, "CDUP", 4) == 0) return handle_cdup(client);
    if (strncmp(client->command, "QUIT", 4) == 0) return handle_quit(client);
    if (strncmp(client->command, "DELE", 4) == 0) return handle_dele(client);
    if (strncmp(client->command, "PWD", 3) == 0) return handle_pwd(client);
    if (strncmp(client->command, "PASV", 4) == 0) return handle_pasv(client);
    if (strncmp(client->command, "PORT", 4) == 0) return handle_port(client);
    if (strncmp(client->command, "HELP", 4) == 0) return handle_help(client);
    if (strncmp(client->command, "NOOP", 4) == 0) return handle_noop(client);
    if (strncmp(client->command, "RETR", 4) == 0) return handle_retr(client);
    if (strncmp(client->command, "STOR", 4) == 0) return handle_stor(client);
    if (strncmp(client->command, "LIST", 4) == 0) return handle_list(client);
    *n = 1;
}

void added_routes(client_t *client, int *n)
{
    *n = 0;
    if (strncmp(client->command, "TYPE", 4) == 0) return handle_type(client);
    *n = 1;
}

void router(client_t *client)
{
    if (client->command == NULL) return;
    int n = 1;
    if (n)
        basic_routes(client, &n);
    if (n)
        added_routes(client, &n);
    if (n)
        send_command(client->command_socket, REPLY_500, client->session_id);
}
