/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

char **get_command(const char *str)
{
    char *string = my_strdup(str);
    size_t length = my_strtoklen(string, " \t");
    if (length == 0) return NULL;
    char **command = malloc(sizeof(char *) * (length + 1));
    command[0] = my_strtok(string, " \t");
    for (size_t i = 1; i < length; i++) {
        command[i] = my_strtok(NULL, " \t");
    }
    command[length] = NULL;
    return command;
}
