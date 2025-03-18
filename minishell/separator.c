/*
** EPITECH PROJECT, 2022
** separator
** File description:
** c
*/
#include "includes/global.h"

int is_separator(char *command, int i, int length)
{
    if (command[i] == ';') {
        return 1;
    }
    return 0;
}

int exec_separators(char *command, char **env)
{
    return 0;
}
