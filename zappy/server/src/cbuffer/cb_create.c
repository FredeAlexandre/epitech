/*
** EPITECH PROJECT, 2022
** cb_create.h
** File description:
** Create a circular buffer
*/

#include "cbuffer.h"

cbuffer_t *cb_create(size_t size)
{
    if (size <= 0 && size > MAX_CBUFFER_SIZE) return NULL;
    cbuffer_t *cb = malloc(sizeof(cbuffer_t));

    if (!cb) return NULL;
    cb->size = size;
    cb->buffer = malloc(sizeof(char) * size);
    cb->read_index = 0;
    cb->write_index = 0;
    cb->empty = 1;
    if (!cb->buffer) {
        free(cb);
        return NULL;
    }
    return cb;
}
