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

int chunk_length(stack *s, int id)
{
    int length = s->length;
    int result = 0;
    item *actual = s->start;
    for (int i = 0; i < length; i++) {
        result += actual->chunk_id == id ? 1 : 0;
        actual = actual->next;
    }
    return result;
}
