/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** init_zappy
*/

#include <stdio.h>
#include <string.h>
#include "zappy.h"

team_t *get_team(const char *name)
{
    team_t *team = get_zappy(NULL)->teams;

    while (team) {
        if (strcmp(team->name, name) == 0)
            return team;
        team = team->next;
    }
    return NULL;
}
