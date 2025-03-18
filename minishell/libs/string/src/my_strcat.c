/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strcat(char *dest, const char *src)
{
    size_t dest_w = my_strlen(dest);
    size_t src_w = my_strlen(src);
    return (char *)my_memcpy(&dest[dest_w], src, src_w + 1);
}
