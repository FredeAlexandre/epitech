/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"

int my_strtok_search(const char *sep, char c, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (sep[i] == c) return 1;
    }
    return 0;
}

size_t my_strtok_skip(const char *str, const char *sep, size_t size)
{
    size_t len = my_strlen(str);
    size_t i = 0;

    for (i = 0; i < len; i++) {
        if (!my_strtok_search(sep, str[i], size)) break;
    }
    return i;
}

size_t my_strtok_next(const char *str, const char *sep, size_t size)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (my_strtok_search(sep, str[i], size)) return i;
    }
    return len;
}

char *my_strtok(char *set_str, const char *sep)
{
    static char *str = NULL;
    static size_t i = 0;
    static size_t len = 0;
    if (set_str != NULL) {
        str = set_str;
        len = my_strlen(str);
        i = 0;
    }
    size_t size = my_strlen(sep);
    i += my_strtok_skip(&str[i], sep, size);
    if (i >= len) return NULL;
    char *result = &str[i];
    i += my_strtok_next(&str[i], sep, size);
    str[i] = '\0';
    i++;
    return result;
}
