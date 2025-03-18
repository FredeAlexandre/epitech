/*
** EPITECH PROJECT, 2022
** check_pipe
** File description:
** c
*/
#include "includes/global.h"

int check_pipe(char *command)
{
    int length = my_strlen(command);
    int nbr_pipes = 0;
    int (*fun_ptr[6])(char *, int, int) = {is_pipe,
        is_right_redir, is_left_redir,
        is_right_dbl_redir, is_left_dbl_redir,
        is_separator};

    for (int i = 0; i < length; i++) {
        for (int x = 0; x < 6; x++) {
            nbr_pipes += (fun_ptr[x])(command, i, length);
        }
    }
    return nbr_pipes;
}
