/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strrchr(char const *str, int ch)
{
    u_char c = (u_char)ch;
    size_t size = my_strlen(str);

    for (size_t i = size; i > 0; i--) {
        if (str[i - 1] == c) return &((char *)str)[i - 1];
    }
    return NULL;
}
