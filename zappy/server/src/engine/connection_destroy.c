/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "zappy.h"

void connection_destroy(connection_t *connection)
{
    if (!connection)
        return;
    cb_destroy(connection->in);
    cb_destroy(connection->out);
    shutdown(connection->socketfd, SHUT_RDWR);
    close(connection->socketfd);
    player_t *player = connection->player;
    free(connection);
    if (player == NULL) return;
    if (player == (void *)IS_GRAPHIC) return;
    player->client = NULL;
    kill_player(player);
}
