/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}
