/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "include/global.h"

void free_stack(stack *s)
{
    item *actual = s->start;
    int length = s->length;
    for (size_t i = 0; i < length; i++) {
        item *next = actual->next;
        free(actual);
        actual = next;
    }
    free(s);
}
