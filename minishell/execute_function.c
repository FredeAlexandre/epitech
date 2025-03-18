/*
** EPITECH PROJECT, 2022
** execute_function
** File description:
** c
*/
#include "includes/global.h"
#include "unistd.h"

void execute_function(char *command, char **env)
{
    char **function = get_command(command);
    char *path = find_executable(function[0]);

    if (path != NULL) {
        execve(path, function, env);
        free(path);
    }
    free(function);
}
