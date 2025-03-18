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

void rollback(stack *s, int chunk)
{
    int counter = 0;
    item *actual = s->start;

    while (actual->prev->chunk_id == chunk) {
        actual = actual->prev;
        counter++;
    }
    for (int i = 0; i < counter; i++) {
        rrotation(s);
    }
}

int transfer_chunk(stack *from)
{
    if (from == NULL) return 0;
    if (from->start == NULL) return 0;
    int chunk = from->start->chunk_id;
    int len = chunk_length(from, chunk);
    int last = len == from->length;
    item *start = chunk_start(from, chunk, last);
    item *stop = chunk_stop(from, chunk, last);
    if (len <= 2) {
        if (len < 2) return chunk;
        swapif(from, start, stop);
        return chunk;
    }
    int mid = get_mid(start, stop, len);
    create_chunk(from, start, stop, mid);
    if (!last) rollback(from, chunk);
    transfer_chunk(from);
}

void transfer_stack(stack *from)
{
    if (from == NULL) return;
    if (from->start == NULL) return;
    int amount = chunk_amount(from);
    for (int i = 0; i < amount; i++) {
        int chunk = transfer_chunk(from);
        int len = chunk_length(from, chunk);
        if (i == amount - 1 && from == stack_a(NULL)) {
            set_sorted();
            continue;
        }
        for (int j = 0; j < len; j++) {
            move(from);
        }
    }
}

int is_sorted(void)
{
    int sorted = stack_a(NULL)->start->chunk_id == -1;
    return sorted && stack_b(NULL)->length == 0;
}

void sort(void)
{
    while (!is_sorted()) {
        transfer_stack(stack_a(NULL));
        transfer_stack(stack_b(NULL));
        set_sorted();
    }
}
