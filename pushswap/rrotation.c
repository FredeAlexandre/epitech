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

void print_rrotation(stack *s)
{
    char action[4] = "\0";
    if (s == stack_a(NULL)) {
        my_strcat(action, "rra");
    } else {
        my_strcat(action, "rrb");
    }
    if (v_enabled(-1)) {
        if (!first_action(-1)) print_divider();
        print_status(action);
    } else {
        if (!first_action(-1)) write(1, " ", 1);
        write(1, action, 3);
    }
    if (first_action(-1)) first_action(0);
}

void rrotation(stack *s)
{
    if (s == NULL || s->length < 2) return;
    s->start = s->start->prev;
    print_rrotation(s);
}

void allrrotation(stack *s)
{
    ((void)s);
    stack *stacka = stack_a(NULL);
    stack *stackb = stack_b(NULL);
    if (stacka != NULL && stacka->length > 1) {
        stacka->start = stacka->start->prev;
    }
    if (stackb != NULL && stackb->length > 1) {
        stackb->start = stackb->start->prev;
    }
    if (v_enabled(-1)) {
        if (!first_action(-1)) print_divider();
        print_status("rrr");
    } else {
        if (!first_action(-1)) write(1, " ", 1);
        write(1, "rrr", 3);
    }
    if (first_action(-1)) first_action(0);
}
