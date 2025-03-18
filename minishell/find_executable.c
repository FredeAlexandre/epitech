/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** c
*/

#include <fcntl.h>
#include <unistd.h>
#include "includes/global.h"

char *find_executable(char *command)
{
    char *path = my_strdup(my_getenv("PATH"));
    char *bin = NULL;
    for (char *i = my_strtok(path, ":"); i != NULL; i = my_strtok(NULL, ":")) {
        size_t a = my_strlen(path);
        size_t b = my_strlen(command);
        bin = malloc(sizeof(char) * (a + b + 2));
        my_memcpy(bin, i, a + 1);
        my_strcat(bin, "/");
        my_strcat(bin, command);
        if (access(bin, X_OK) == 0) break;
        free(bin);
        bin = NULL;
    }
    free(path);
    return bin;
}
