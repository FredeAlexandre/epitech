/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

void *my_memcpy(void *dest, const void *src, size_t max)
{
    for (size_t i = 0; i < max; i++) {
        ((u_char *)dest)[i] = ((u_char *)src)[i];
    }
    return dest;
}
