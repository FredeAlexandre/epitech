/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

int my_rmslotenv(void)
{
    char **old_env = my_environ();
    size_t length = my_lengthenv(old_env);
    char **new_env = malloc(sizeof(char *) * (length));
    for (size_t i = 0; i < length - 1; i++) {
        new_env[i] = my_strdup(old_env[i]);
    }
    new_env[length - 1] = NULL;
    my_clearenv();
    my_storenv(new_env);
    return 0;
}
