/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int handle_guard(client_t *client)
{
    int csocket = client->command_socket;
    if (client->is_auth == 0) {
        send_command(csocket, REPLY_530, client->session_id);
        return -1;
    }
    int socketdata = setdata(client);
    if (socketdata == -1) {
        send_command(csocket, REPLY_425, client->session_id);
        return -1;
    }
    if (socketdata == 0) {
        send_command(csocket, REPLY_425, client->session_id);
        return -1;
    }
    return 0;
}
