/*
** EPITECH PROJECT, 2022
** my_puts
** File description:
** Print a string as it on stdout
*/

#include "../../string/include/global.h"
#include <unistd.h>
#include "../include/global.h"

int my_puts(const char *str)
{
    int result = my_strlen(str) + 1;
    char *newone = malloc(result);
    my_strcpy(newone, str);
    newone[0] = '\n';
    if (write(1, newone, result) < 0) return -1;
    free(newone);
    return result;
}
