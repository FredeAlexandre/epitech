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

void move_remove(stack *s1, item *i)
{
    if (s1->length == 1) {
        s1->start = NULL;
    } else {
        item *next = i->next;
        i->prev->next = i->next;
        next->prev = i->prev;
        s1->start = next;
    }
    s1->length--;
}

void move_add(stack *s2, item *i)
{
    if (s2->length == 0) {
        i->next = i;
        i->prev = i;
        s2->start = i;
    } else {
        i->next = s2->start;
        i->prev = s2->start->prev;
        s2->start->prev->next = i;
        s2->start->prev = i;
        s2->start = i;
    }
    s2->length++;
}

void print_move(stack *s1)
{
    char action[3] = "\0";
    if (s1 == stack_a(NULL)) {
        my_strcat(action, "pb");
    } else {
        my_strcat(action, "pa");
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

void move(stack *s1)
{
    stack *s2 = s1 == stack_a(NULL) ? stack_b(NULL) : stack_a(NULL);
    if (s1 == NULL || s2 == NULL) return;
    if (s1->length == 0) return;
    item *i = s1->start;
    move_remove(s1, i);
    move_add(s2, i);
    print_move(s1);
}
