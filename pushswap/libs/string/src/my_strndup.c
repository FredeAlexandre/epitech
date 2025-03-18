/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strndup(const char *source, size_t n)
{
    size_t length = my_strlen(source);
    if (length < n) n = length;
    char* result = malloc(sizeof(char) * (n + 1));
    my_memcpy(result, source, n);
    result[n] = '\0';
    return result;
}
