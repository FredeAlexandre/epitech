/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "include/global.h"

stack *create_stack(void)
{
    stack *i = malloc(sizeof(stack));
    i->length = 0;
    i->start = NULL;
    return i;
}
