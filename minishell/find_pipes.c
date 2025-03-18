/*
** EPITECH PROJECT, 2022
** find_pipes
** File description:
** c
*/
#include "includes/global.h"

int is_pipe(char *command, int i, int length)
{
    if (command[i] == '|') {
        return 1;
    }
    return 0;
}

int is_right_redir(char *command, int i, int length)
{
    if (command[i] == '>') {
        return 1;
    }
    return 0;
}

int is_left_redir(char *command, int i, int length)
{
    if (command[i] == '<') {
        return 1;
    }
    return 0;
}

int is_right_dbl_redir(char *command, int i, int length)
{
    if (i >= length - 2) return 0;
    if (command[i] == '>') {
        if (command[i + 1] == '>') {
            return 1;
        }
    }
    return 0;
}

int is_left_dbl_redir(char *command, int i, int length)
{
    if (i >= length - 2) return 0;
    if (command[i] == '<') {
        if (command[i + 1] == '<') {
            return 1;
        }
    }
    return 0;
}
