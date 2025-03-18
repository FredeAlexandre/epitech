/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>
#include "include/global.h"

void add_item(int v, stack *stack)
{
    item *i = malloc(sizeof(item));
    i->chunk_id = 0;
    i->value = v;
    item *start = stack->start;
    if (start == NULL) {
        i->next = i;
        i->prev = i;
        stack->start = i;
    } else {
        item *last = start->prev;
        i->next = start;
        i->prev = last;
        last->next = i;
        start->prev = i;
    }
    stack->length++;
}
