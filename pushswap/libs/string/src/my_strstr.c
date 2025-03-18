/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strstr(const char *full, const char *query)
{
    size_t flen = my_strlen(full);
    size_t qlen = my_strlen(query);

    if (qlen == 0) return (char *)full;
    if (qlen > flen) return NULL;
    for (size_t i = 0; i < qlen; i++) {
        if (full[i] != query[i]) return my_strstr(&full[1], query);
    }
    return (char *)full;
}
