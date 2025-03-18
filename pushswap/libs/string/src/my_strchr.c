/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strchr(char const *str, int ch)
{
    return my_memchr(str, ch, my_strlen(str));
}
