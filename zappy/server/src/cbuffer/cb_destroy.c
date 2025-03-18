/*
** EPITECH PROJECT, 2022
** cb_destroy.h
** File description:
** Clean a circular buffer
*/

#include "cbuffer.h"

void cb_destroy(cbuffer_t *cb)
{
    free(cb->buffer);
    free(cb);
}
