/*
** EPITECH PROJECT, 2022
** main
** File description:
** main funcftion
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/global.h"

size_t my_arrlen(char **arr)
{
    size_t i = 0;
    while (arr[i] != NULL) {
        i++;
    }
    return i;
}
