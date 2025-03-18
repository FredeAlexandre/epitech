/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

int get_absolute_k(player_t *from, player_t *to, int width, int height)
{
    int cdx = to->x - from->x;
    int rdx = cdx > 0 ? -(width - cdx) : width + cdx;
    int vdx = cdx > 0 ? cdx > -rdx ? cdx : rdx : -cdx > rdx ? cdx : rdx;

    int cdy = to->y - from->y;
    int rdy = cdy > 0 ? height - cdy : height + cdy;
    int vdy = cdy > 0 ? cdy > -rdy ? cdy : rdy : -cdy > rdy ? cdy : rdy;

    if (vdx == vdy && vdx > 0) return 2;
    if (vdx == vdy && vdx < 0) return 6;
    if (vdx == -vdy && vdx > 0) return 4;
    if (vdx == -vdy && vdx < 0) return 8;
    if (vdx > vdy && ((vdx > 0 && vdy > 0) || (vdx > 0 && vdy < 0))) return 3;
    if (vdx < vdy && ((vdx < 0 && vdy > 0) || (vdx < 0 && vdy < 0))) return 7;
    if (vdx < vdy && ((vdx < 0 && vdy < 0) || (vdx < 0 && vdy > 0))) return 1;
    if (vdx > vdy && ((vdx > 0 && vdy < 0) || (vdx < 0 && vdy < 0))) return 5;
    return 0;
}

int get_relative_k(player_t *from, player_t *to, int width, int height)
{
    int k = get_absolute_k(from, to, width, height);
    int direction = to->direction;
    for (int i = 0; i < direction; i++) {
        k = k == 8 ? 1 : k + 1;
        k = k == 8 ? 1 : k + 1;
    }
    return k;
}

void broadcast_to(player_t *from, player_t *to)
{
    zappy_t *zappy = get_zappy(NULL);
    int width = zappy->map->width;
    int height = zappy->map->height;
    int k = get_relative_k(from, to, width, height);
    char result[OUT_BUFFER_SIZE];
    bzero(result, OUT_BUFFER_SIZE);
    sprintf(result, "message %i, %s", k, from->options);
    send_message(to->client, result);
}

void broadcast_action(player_t *player)
{
    zappy_t *zappy = get_zappy(NULL);

    team_t *team = zappy->teams;

    while (team) {
        player_t *actual = team->players;

        while (actual) {
            if (actual->client && actual->id != player->id) {
                broadcast_to(player, actual);
            }
            actual = actual->next;
        }

        team = team->next;
    }
    char buffer[OUT_BUFFER_SIZE];
    sprintf(buffer, "pbc %d %s", player->id, player->options);
    graphic_broadcast(buffer);
    free(player->options);
    player->options = NULL;
    player->action = NULL;
    if (player->client) send_message(player->client, "ok");
}
