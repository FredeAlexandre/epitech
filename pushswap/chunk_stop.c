/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/global.h"

item *chunk_stop(stack *s, int id, int last)
{
    if (last) return s->start->prev;
    int length = s->length;
    item *actual = s->start;
    while (actual->chunk_id != id) {
        actual = actual->prev;
    }
    while (actual->next->chunk_id == id) {
        actual = actual->next;
    }
    return actual;
}
