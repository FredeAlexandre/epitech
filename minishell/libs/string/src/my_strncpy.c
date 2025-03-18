/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t length = my_strlen(src);
    if (length < n) n = length;
    char *result = my_memcpy(dest, src, n);
    if (length > n) return result;
    result[n] = '\0';
    return result;
}
