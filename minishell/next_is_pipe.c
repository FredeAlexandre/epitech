/*
** EPITECH PROJECT, 2022
** next_is_pipe
** File description:
** c
*/
#include "includes/global.h"

int second_for(char *command, int i, int length)
{
    int (*fun_ptr[6])(char *, int, int) = {is_pipe,
        is_right_redir, is_left_redir,
        is_right_dbl_redir, is_left_dbl_redir,
        is_separator};

    for (int x = 0; x < 6; x++) {
        if ((fun_ptr[x])(command, i, length) != 0) return (x + 1);
    }
    return 0;
}

int next_redirection(char *command)
{
    int length = my_strlen(command);
    int result;

    for (int i = 0; i < length; i++) {
        result = second_for(command , i, length);
        if (result != 0) return result;
    }
    return 0;
}
