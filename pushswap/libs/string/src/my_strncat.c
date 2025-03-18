/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_w = my_strlen(dest);
    char *result = (char *)my_memcpy(&dest[dest_w], src, n);
    result[n] = '\0';
    return result;
}
