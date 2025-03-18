/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strpbrk(const char *str, const char *s)
{
    size_t result = my_strcspn(str, s);
    if (str[result] == '\0') return NULL;
    return &((char *)str)[result];
}
