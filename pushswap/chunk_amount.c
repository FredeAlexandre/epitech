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

int chunk_amount(stack *s)
{
    if (s->length == 0) return 0;
    int length = s->length;
    int result = 1;
    item *actual = s->start;
    for (int i = 0; i < length; i++) {
        int id1 = actual->chunk_id;
        int id2 = actual->next->chunk_id;
        if (id1 == -1 || id2 == -1) continue;
        if (id1 != id2) result++;
        actual = actual->next;
    }
    return result;
}
