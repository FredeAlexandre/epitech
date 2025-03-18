/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/global.h"

int issorted(item *i)
{
    int value = i->value;
    item *actual = i;
    while (actual != stack_a(NULL)->start) {
        if (actual->value > value) return 0;
        actual = actual->prev;
    }
    if (actual->value > value) return 0;
    return 1;
}

void set_sorted(void)
{
    stack *stacka = stack_a(NULL);
    if (stacka == NULL) return;
    int length = stacka->length;
    if (length == 0 || length == 1) return;
    item *last = stacka->start->prev;
    int sorted = 0;
    int value = 0;
    while (last->chunk_id == -1 && sorted < length) {
        last = last->prev;
        sorted++;
    }
    for (int i = 0; i < length - sorted; i++) {
        int sorted = issorted(last);
        if (!sorted) return;
        last->chunk_id = -1;
        last = last->prev;
    }
}
