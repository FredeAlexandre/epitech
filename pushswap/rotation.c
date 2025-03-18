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

void print_rotation(stack *s)
{
    char action[3] = "\0";
    if (s == stack_a(NULL)) {
        my_strcat(action, "ra");
    } else {
        my_strcat(action, "rb");
    }
    if (v_enabled(-1)) {
        if (!first_action(-1)) print_divider();
        print_status(action);
    } else {
        if (!first_action(-1)) write(1, " ", 1);
        write(1, action, 2);
    }
    if (first_action(-1)) first_action(0);
}

void rotation(stack *s)
{
    if (s == NULL || s->length < 2) return;
    s->start = s->start->next;
    print_rotation(s);
}

void allrotation(stack *s)
{
    ((void)s);
    stack *stacka = stack_a(NULL);
    stack *stackb = stack_b(NULL);
    if (stacka != NULL && stacka->length > 1) {
        stacka->start = stacka->start->next;
    }
    if (stackb != NULL && stackb->length > 1) {
        stackb->start = stackb->start->next;
    }
    if (v_enabled(-1)) {
        if (!first_action(-1)) print_divider();
        print_status("rr");
    } else {
        if (!first_action(-1)) write(1, " ", 1);
        write(1, "rr", 2);
    }
    if (first_action(-1)) first_action(0);
}
