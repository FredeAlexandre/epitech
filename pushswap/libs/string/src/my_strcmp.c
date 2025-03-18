/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"

int my_strcmp(char const *str1, char const *str2)
{
    size_t a = my_strlen(str1);
    size_t b = my_strlen(str2);
    size_t c = a > b ? a : b;
    return my_memcmp(str1, str2, c);
}
