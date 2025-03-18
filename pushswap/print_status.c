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

void writec(char *c, int b)
{
    if (b == 1) {
        write(1, "\e[1;33m", 7);
    } else if (b == 2) {
        write(1, "\e[1;31m", 7);
    } else {
        write(1, "\e[1;37m", 7);
    }
    write(1, c, 1);
    write(1, "\e[0m", 4);
}

void print_number(int number, int c)
{
    if (number == 0) return writec("0", c);
    if (number < 0) {
        number = -number;
        writec("-", c);
    }
    char num = (number % 10) + '0';
    number /= 10;
    if (number > 0) {
        print_number(number, c);
        writec(&num, c);
    } else {
        writec(&num, c);
    }
}

void print_stack(stack *s)
{
    int length = s->length;
    item *actual = s->start;
    write(1, "[", 1);
    for (int i = 0; i < length; i++) {
        int sep = actual->chunk_id != actual->next->chunk_id;
        int c = actual->chunk_id == -1 ? 2 : sep;
        print_number(actual->value, c);
        if (i != length - 1) write(1, ", ", 2);
        actual = actual->next;
    }
    write(1, "] ", 2);
}

void print_status(char *action)
{
    stack *stacka = stack_a(NULL);
    stack *stackb = stack_b(NULL);
    write(1, "Action: ", 8);
    write(1, action, my_strlen(action));
    write(1, "\n", 1);
    write(1, "Stack A: ", 9);
    print_stack(stacka);
    print_number(stacka->length, 0);
    write(1, "\n", 1);
    write(1, "Stack B: ", 9);
    print_stack(stackb);
    print_number(stackb->length, 0);
    write(1, "\n", 1);
}
