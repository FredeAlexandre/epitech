/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

void *my_memccpy(void *dest, const void *src, int ch, size_t max)
{
    void *end = my_memchr(src, ch, max);
    size_t i = 0;

    if (end == NULL) return NULL;
    for (i = 0; &((u_char *)src)[i] != end; i++) {
        ((u_char *)dest)[i] = ((u_char *)src)[i];
    }
    ((u_char *)dest)[i] = ((u_char *)src)[i];
    return &((u_char *)dest)[i + 1];
}
