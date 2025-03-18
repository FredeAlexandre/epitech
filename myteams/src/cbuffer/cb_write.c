/*
** EPITECH PROJECT, 2022
** cb_write.h
** File description:
** Create a circular buffer
*/

#include "cbuffer.h"

size_t cb_write(cbuffer_t *cb, const char *buffer, size_t size)
{
    size_t i = 0;
    size_t write_index = cb->write_index;

    if (cb->empty == 1) {
        cb->buffer[write_index] = buffer[i];
        cb->empty = 0;
        i++;
    }

    if (!cb || !buffer || !size) return 0;
    for (; i < size; i++) {
        write_index = (write_index + 1) % cb->size;
        if (write_index == cb->read_index) break;
        cb->buffer[write_index] = buffer[i];
    }
    if (write_index == cb->read_index) write_index--;
    cb->write_index = write_index;
    return i;
}
