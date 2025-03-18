/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"

int my_strncmp(char const *str1, char const *str2, size_t n)
{
    return my_memcmp(str1, str2, n);
}
