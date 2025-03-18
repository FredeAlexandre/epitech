/*
** EPITECH PROJECT, 2022
** cb_read.h
** File description:
** Read the buffer from last cosumed byte
*/

#include "cbuffer.h"

size_t cb_read(cbuffer_t *cb, char *buffer, size_t size)
{
    if (!cb || !buffer || !size) return 0;
    size_t i = 0;
    size_t read_index = cb->read_index;

    if (cb->empty == 1) return 0;
    for (; i < size; i++) {
        buffer[i] = cb->buffer[read_index];
        if (read_index == cb->write_index) {
            i++;
            break;
        }
        read_index = (read_index + 1) % cb->size;
    }
    return i;
}
