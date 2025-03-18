/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strdup(const char *source)
{
    size_t length = my_strlen(source);
    char* result = malloc(sizeof(char) * (length + 1));
    my_memcpy(result, source, length);
    result[length] = '\0';
    return result;
}
