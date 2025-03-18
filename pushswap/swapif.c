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

void swapif(stack *s, item *start, item *stop)
{
    if (s == stack_a(NULL)) {
        if (start->value > stop->value) swap(s);
    } else {
        if (start->value < stop->value) swap(s);
    }
}
