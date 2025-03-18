/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

void *my_memmove(void *dest, const void *src, size_t max)
{
    u_char *tmp = malloc(sizeof(u_char) * (max));
    for (size_t i = 0; i < max; i++) {
        tmp[i] = ((u_char *)src)[i];
    }
    for (size_t i = 0; i < max; i++) {
        ((u_char *)dest)[i] = tmp[i];
    }
    free(tmp);
    return dest;
}
