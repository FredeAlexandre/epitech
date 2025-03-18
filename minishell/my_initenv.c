/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

char **my_initenv(char **new_env)
{
    size_t length = my_lengthenv(new_env);
    char **env = malloc(sizeof(char *) * (length + 1));
    for (size_t i = 0; i < length; i++) {
        env[i] = my_strdup(new_env[i]);
    }
    env[length] = NULL;
    return my_storenv(env);
}
