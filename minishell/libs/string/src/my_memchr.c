/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

void *my_memchr(const void *mem_block, int ch, size_t size)
{
    u_char c = (u_char)ch;

    for (size_t i = 0; i < size; i++) {
        u_char a = ((u_char *)mem_block)[i];
        if (a == c) return &((u_char *)mem_block)[i];
    }
    return NULL;
}
