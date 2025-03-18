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

void rset_action(connection_t *connection, action_t action, int time, const char *options)
{
    zappy_t *zappy = get_zappy(NULL);
    player_t *player = ((player_t *)connection->player);
    player->action = action;
    player->options = strdup(options);
    long timeout = time * TIME_UNIT / zappy->freq;
    int seconds = timeout / TIME_UNIT;
    int nanoseconds = timeout % TIME_UNIT;
    clock_gettime(CLOCK_MONOTONIC, &player->action_timeout);
    player->action_timeout.tv_sec += seconds;
    player->action_timeout.tv_nsec += nanoseconds;
}

void bots_router(connection_t *connection, const char *command)
{
    if (strncmp(command, "Forward", 7) == 0) return rset_action(connection, &forward_action, 7, "");
    if (strncmp(command, "Right", 5) == 0) return rset_action(connection, &right_action, 7, "");
    if (strncmp(command, "Left", 4) == 0) return rset_action(connection, &left_action, 7, "");
    if (strncmp(command, "Look", 4) == 0) return rset_action(connection, &look_action, 7, "");
    if (strncmp(command, "Inventory", 9) == 0) return rset_action(connection, &inventory_action, 1, "");
    if (strncmp(command, "Broadcast", 9) == 0) return rset_action(connection, &broadcast_action, 7, command + 10);
    if (strncmp(command, "Connect_nbr", 11) == 0) return rset_action(connection, &connect_nbr_action, 0, "");
    if (strncmp(command, "Fork", 4) == 0) {
        char buffer[OUT_BUFFER_SIZE];
        sprintf(buffer, "pfk %d", ((player_t *)connection->player)->id);
        graphic_broadcast(buffer);
        return rset_action(connection, &fork_action, 42, "");
    }
    if (strncmp(command, "Eject", 5) == 0) return rset_action(connection, &eject_action, 7, "");
    if (strncmp(command, "Take", 4) == 0) return rset_action(connection, &take_action, 7, command + 5);
    if (strncmp(command, "Set", 3) == 0) return rset_action(connection, &set_action, 7, command + 4);
    // if (strncmp(command, "Incantation", 11) == 0) return rset_action(connection, &incantation_action, 300, "");
    send_message(connection, "suc");
}
