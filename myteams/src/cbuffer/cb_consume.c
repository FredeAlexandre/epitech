/*
** EPITECH PROJECT, 2022
** cb_write.h
** File description:
** Create a circular buffer
*/

#include <string.h>

#include "cbuffer.h"

size_t cb_consume(cbuffer_t *cb, char *buffer, size_t size)
{
    size_t i = 0;
    size_t read_index = cb->read_index;

    if (cb->empty == 1) return 0;

    if (!cb || !size) return 0;
    for (; i < size; i++) {
        if (buffer != NULL) buffer[i] = cb->buffer[read_index];
        if (read_index == cb->write_index) break;
        read_index = (read_index + 1) % cb->size;
    }
    if (read_index == cb->write_index) cb->empty = 1;
    cb->read_index = read_index;
    if (read_index == cb->write_index) i++;
    return i;
}
