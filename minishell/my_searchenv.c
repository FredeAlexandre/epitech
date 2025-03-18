/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

size_t my_searchenv(const char *name)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    size_t name_length = my_strlen(name);
    for (size_t i = 0; i < length; i++) {
        if (my_memcmp(name, env[i], name_length) == 0) return i;
    }
    return length;
}
