/*
** EPITECH PROJECT, 2022
** get_server.c
** File description:
** Save the server globaly
*/

#include "server.h"

server_t *get_server(server_t* new_server)
{
    static server_t *saved_server = NULL;

    if (new_server != NULL) saved_server = new_server;

    return saved_server;
}
