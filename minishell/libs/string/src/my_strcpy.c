/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "../include/global.h"

char *my_strcpy(char *dest, char const *src)
{
    return my_memcpy(dest, src, my_strlen(src) + 1);
}
