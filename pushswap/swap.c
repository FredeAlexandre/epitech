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

void print_swap(stack *s)
{
    char action[3] = "\0";
    if (s == stack_a(NULL)) {
        my_strcat(action, "sa");
    } else {
        my_strcat(action, "sb");
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

void swap_internal(stack *s)
{
    if (s == NULL) return;
    if (s->length == 0 || s->length == 1) return;
    s->start = s->start->next;
    if (s->length == 2) return;
    item *a = s->start->prev;
    item *b = s->start;
    item *a_prev = a->prev;
    item *b_next = b->next;
    a->prev = b;
    b->next = a;
    a->next = b_next;
    b->prev = a_prev;
    a_prev->next = b;
    b_next->prev = a;
}

void swap(stack *s)
{
    swap_internal(s);
    print_swap(s);
}

void allswap(void)
{
    swap_internal(stack_a(NULL));
    swap_internal(stack_b(NULL));
    if (v_enabled(-1)) {
        if (!first_action(-1)) print_divider();
        print_status("sc");
    } else {
        if (!first_action(-1)) write(1, " ", 1);
        write(1, "sc", 2);
    }
    if (first_action(-1)) first_action(0);
}
