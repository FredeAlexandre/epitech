/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

int my_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        int cmp = ((u_char *)ptr1)[i] - ((u_char *)ptr2)[i];
        if (cmp) return cmp;
    }
    return 0;
}
