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

item *chunk_start(stack *s, int id, int last)
{
    if (last) return s->start;
    int length = s->length;
    item *actual = s->start;
    while (actual->chunk_id != id) {
        actual = actual->next;
    }
    while (actual->prev->chunk_id == id) {
        actual = actual->prev;
    }
    return actual;
}
