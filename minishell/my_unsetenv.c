/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

int my_unsetenv(const char *name)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    size_t i = my_searchenv(name);
    if (i == length) return 0;
    char *tmp = env[i];
    env[i] = env[length - 1];
    env[length - 1] = tmp;
    my_rmslotenv();
    return 0;
}
