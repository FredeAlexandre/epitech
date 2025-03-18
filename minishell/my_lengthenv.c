/*
** EPITECH PROJECT, 2022
** my_lengthenv
** File description:
** Return the length of environement array
*/
#include "includes/global.h"

size_t my_lengthenv(char **env)
{
    size_t length = 0;
    for (size_t i = 0; env[i] != NULL; i++) {
        length++;
    }
    return length;
}
