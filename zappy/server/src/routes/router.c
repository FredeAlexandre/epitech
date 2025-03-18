/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <strings.h>

#include "zappy.h"

void check_routes(connection_t *connection, char *command)
{
    if (connection->player == (void *)IS_GRAPHIC) return graphicals_router(connection, command);
    if (connection->player != NULL) return bots_router(connection, command);
    send_message(connection, "UNKNOWN ENTITY");
}

int graphic_auth(connection_t *connection, const char *team_name)
{
    if (strcmp(team_name, IS_GRAPHIC) != 0) return 0;
    connection->player = IS_GRAPHIC;
    msz_route(connection);
    sgt_route(connection);
    mct_route(connection);
    tna_route(connection);
    return 1;
}

void auth_response(connection_t *connection, const team_t *team)
{
    zappy_t *zappy = get_zappy(NULL);
    int width = zappy->map->width;
    int height = zappy->map->height;
    int slots = 0;
    if (team) {
        player_t *player = team->players;
        while (player) {
            if (player->client == NULL) slots++;
            player = player->next;
        }
    }
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "%d", slots);
    send_message(connection, buffer);
    sprintf(buffer, "%d %d", width, height);
    send_message(connection, buffer);
}

void auth(connection_t *connection, const char *team_name)
{
    if (graphic_auth(connection, team_name)) return;
    team_t *team = get_team(team_name);

    if (!team) {
        send_message(connection, "ko");
        return;
    }
    player_t *player = team->players;
    while (player) {
        if (player->client == NULL) break;
        player = player->next;
    }
    if (player == NULL) {
        send_message(connection, "ko");
        return;
    }
    player->client = connection;
    connection->player = player;
    get_tile(player->x, player->y)->players_amount++;
    auth_response(connection, team);
}

void router(void)
{
    server_t *server = get_server(NULL);
    server_node_t *node = server->head;
    server_node_t *tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;

        player_t * player = ((player_t *)tmp->connection->player);
        if ((player != NULL && player != (void *)IS_GRAPHIC) && player->action != NULL)
            continue;

        char command[MAX_COMMAND_SIZE];

        size_t result = recv_message(tmp->connection, command, MAX_COMMAND_SIZE);
        if (result == 0) continue;
        if (tmp->connection->player == NULL) {
            auth(tmp->connection, command);
            continue;
        }
        check_routes(tmp->connection, command);
    }
}
