/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

team_t *get_team_of(const player_t *player)
{
    team_t *team = get_zappy(NULL)->teams;

    while (team) {
        player_t *actual = team->players;
        while (actual) {
            if (actual->id == player->id)
                return team;
            actual = actual->next;
        }
        team = team->next;
    }
    return NULL;
}
