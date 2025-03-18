/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

void free_command(char **command)
{
    free(command);
}
