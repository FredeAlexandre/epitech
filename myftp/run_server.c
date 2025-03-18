/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "myftp.h"

void remove_client(list_t *clients, list_node_t *client_node)
{
    client_t *client = AS_CLIENT(client_node->data);
    clean_client(client);
    list_remove(clients, client_node);
}

void set_readfs(int *nfds, fd_set *readfs, list_t *clients, int main_socket)
{
    list_node_t *node = clients->head;
    *nfds = main_socket;

    FD_ZERO(readfs);
    FD_SET(main_socket, readfs);
    while (node != NULL) {
        client_t *client = AS_CLIENT(node->data);
        if (client->command_socket == 0) {
            list_node_t *to_remove = node;
            node = node->next;
            remove_client(clients, to_remove);
            continue;
        }
        FD_SET(client->command_socket, readfs);
        if (client->command_socket > *nfds)
            *nfds = client->command_socket;
        node = node->next;
    }
    *nfds += 1;
}

void handle_commands(list_t *clients, fd_set *readfs)
{
    list_node_t *node = clients->head;
    list_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        client_t *client = AS_CLIENT(node->data);
        int isset = FD_ISSET(client->command_socket, readfs);
        if (isset && handle_command(client) == SOCKET_CLOSED) {
            printf(SERVER_PREFIX "Client disconnected !\n");
            remove_client(clients, node);
        }
        node = next;
    }
}

void add_client(list_t *clients, int main_socket)
{
    int client_socket = accept(main_socket, NULL, NULL);
    client_t *client = malloc(sizeof(client_t));

    if (client_socket == -1) {
        perror(SERVER_PREFIX "`accept` failed");
        exit(84);
    }
    client->session_id = clients->size + 1;
    client->command_socket = client_socket;
    client->data_socket = 0;
    client->is_auth = 0;
    client->username = NULL;
    client->password = NULL;
    client->pwd = getcwd(NULL, 0);
    list_add(clients, client);
    send_command(client_socket, REPLY_220, client->session_id);
}

void run_server(list_t *clients, int main_socket)
{
    fd_set readfs;
    int nfds = 0;
    struct timeval timeout = {0, 100000};

    set_readfs(&nfds, &readfs, clients, main_socket);
    if (select(nfds, &readfs, NULL, NULL, &timeout) == -1) {
        if (errno == EINTR)
            return;
        perror(SERVER_PREFIX "`select` failed");
        exit(84);
    }
    if (FD_ISSET(main_socket, &readfs)) {
        printf(SERVER_PREFIX "New client connected !\n");
        add_client(clients, main_socket);
    }
    handle_commands(clients, &readfs);
}
