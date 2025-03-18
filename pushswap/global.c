/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/global.h"

stack *stack_a(stack *si)
{
    static stack *s = NULL;
    if (si != NULL) {
        s = si;
    }
    return s;
}

stack *stack_b(stack *si)
{
    static stack *s = NULL;
    if (si != NULL) {
        s = si;
    }
    return s;
}

int v_enabled(int i)
{
    static int v = 0;
    if (i != -1) {
        v = i;
    }
    return v;
}

int chunk_id(int i)
{
    static int v = 0;
    if (i != -1) {
        v = i;
    }
    return v;
}

int first_action(int i)
{
    static int v = 1;
    if (i != -1) {
        v = i;
    }
    return v;
}
