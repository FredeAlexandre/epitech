/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/

#include <stdio.h>
#include "includes/global.h"

int my_putenv(char *string)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    char *copy = my_strdup(string);
    size_t i = my_searchenv(my_strtok(copy, "="));
    free(copy);
    if (i == length) {
        my_addslotenv();
        env = my_environ();
    }
    env[i] = my_strdup(string);
    return 0;
}
