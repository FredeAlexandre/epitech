/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"
#include "../../string/include/global.h"

size_t my_strtoklen(char *set_str, const char *sep)
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
    if (i >= len) return 0;
    i += my_strtok_next(&str[i], sep, size);
    if (i >= len) return 1;
    i++;
    if (i >= len) return 1;
    return my_strtoklen(NULL, sep) + 1;
}
