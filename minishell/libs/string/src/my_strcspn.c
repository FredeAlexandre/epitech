/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

int my_strcspn_internal(char const *rejects, char c, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (rejects[i] == c) return 1;
    }
    return 0;
}

size_t my_strcspn(char const *str, char const *r)
{
    size_t i = 0;
    size_t length = my_strlen(r);

    while (!(str[i] == '\0' || my_strcspn_internal(r, str[i], length))) {
        i++;
    }
    return i;
}
