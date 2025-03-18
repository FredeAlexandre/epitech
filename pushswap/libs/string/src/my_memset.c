/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

void *my_memset(void *ptr, int v, size_t count)
{
    for (size_t i = 0; i < count; i++) {
        ((u_char *)ptr)[i] = (u_char)v;
    }
    return ptr;
}
