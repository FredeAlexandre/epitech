/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "../myftp.h"

int setdata_pasv(client_t *client)
{
    client->data_socket = accept(client->root_socket, NULL, NULL);
    return client->data_socket;
}

int setdata_port(client_t *client)
{
    struct sockaddr_in a = client->client;
    if (connect(client->data_socket, (struct sockaddr *)&a, sizeof(a)) == -1)
        return -1;
    return client->data_socket;
}

int setdata(client_t *client)
{
    if (client->data_type == DATA_ACTIVE)
        return setdata_port(client);
    if (client->data_type == DATA_PASSIVE)
        return setdata_pasv(client);
    client->data_type = DATA_NONE;
    return 0;
}
