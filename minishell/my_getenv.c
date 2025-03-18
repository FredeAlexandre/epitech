/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

char *my_getenv(const char *name)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    size_t i = my_searchenv(name);
    if (i == length) return NULL;
    char *str = env[i];
    for (size_t j = 0; !(str[0] == '\0' || str[0] == '='); j++) {
        str = &str[1];
    }
    if (str[0] == '\0') return NULL;
    return &str[1];
}
