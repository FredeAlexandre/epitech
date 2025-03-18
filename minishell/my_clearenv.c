/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

int my_clearenv(void)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    for (size_t i = 0; i < length; i++) {
        free(env[i]);
    }
    free(env);
    return 0;
}
