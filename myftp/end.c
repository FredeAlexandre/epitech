/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Initialisation function
*/

#include "myftp.h"

void clean_client(client_t *client)
{
    if (client->command_socket > 0) close(client->command_socket);
    if (client->data_socket > 0) close(client->data_socket);
    if (client->root_socket)
        close(client->root_socket);
    if (client->username) free(client->username);
    if (client->password) free(client->password);
    if (client->command) free(client->command);
    free(client->pwd);
    free(client);
}

void end(list_t *clients, int main_socket)
{
    list_node_t *node = clients->head;
    list_node_t *next = NULL;
    while (node != NULL) {
        next = node->next;
        client_t *client = AS_CLIENT(node->data);
        clean_client(client);
        free(node);
        node = next;
    }
    free(clients);
    close(main_socket);
    printf(SERVER_PREFIX "Server closed !\n");
}
