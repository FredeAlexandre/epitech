/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

int my_strspn_internal(char const *rejects, char c, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (rejects[i] == c) return 1;
    }
    return 0;
}

size_t my_strspn(char const *str, char const *a)
{
    size_t i = 0;
    size_t length = my_strlen(a);

    while (!(str[i] == '\0' || !my_strspn_internal(a, str[i], length))) {
        i++;
    }
    return i;
}
