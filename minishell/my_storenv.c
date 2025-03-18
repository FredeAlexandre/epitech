/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

char **my_storenv(char **new_env)
{
    static char** env = NULL;
    if (new_env != NULL) {
        env = new_env;
    }
    return env;
}
