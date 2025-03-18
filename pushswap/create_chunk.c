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

item *move_item(stack *s, item* i, int mid)
{
    int low = s == stack_a(NULL) ? 1 : 0;
    int m = 0;
    if (low && i->value < mid) m = 1;
    if (!low && i->value > mid) m = 1;
    item *next = i->next;
    if (m) {
        i->chunk_id = chunk_id(-1);
        move(s);
    } else {
        rotation(s);
    }
    return next;
}

void create_chunk(stack *s, item *start, item *stop, int mid)
{
    item *actual = start;
    chunk_id(chunk_id(-1) + 1);
    while (actual != stop) {
        actual = move_item(s, actual, mid);
    }
    move_item(s, actual, mid);
}
