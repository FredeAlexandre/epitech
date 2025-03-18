/*
** EPITECH PROJECT, 2022
** env
** File description:
** c
*/
#include "includes/global.h"

int my_setenv(const char *name, const char *value, int overwrite)
{
    char **env = my_environ();
    size_t length = my_lengthenv(env);
    size_t i = my_searchenv(name);
    size_t name_length = my_strlen(name);
    if (i != length && !overwrite) return 0;
    if (i == length) {
        my_addslotenv();
        env = my_environ();
    } else {
        free(env[i]);
    }
    char *string = malloc(name_length + my_strlen(value) + 2);
    my_memcpy(string, name, name_length);
    string[name_length] = '\0';
    my_strcat(string, "=");
    my_strcat(string, value);
    env[i] = string;
    return 0;
}
