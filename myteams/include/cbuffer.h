/*
** EPITECH PROJECT, 2022
** cbuffer.h
** File description:
** The architecture of the circular buffer
*/

#include <stdlib.h>

#ifndef _ZAPPY_SERVER_CBUFFER_
#define _ZAPPY_SERVER_CBUFFER_

#define MAX_CBUFFER_SIZE 4096

typedef struct {
    char *buffer;
    size_t size;
    size_t read_index;
    size_t write_index;
    int empty;
} cbuffer_t;

cbuffer_t *cb_create(size_t size);
void cb_destroy(cbuffer_t *cb);

size_t cb_read(cbuffer_t *cb, char *buffer, size_t size);
size_t cb_write(cbuffer_t *cb, const char *buffer, size_t size);
size_t cb_consume(cbuffer_t *cb, char *buffer, size_t size);

size_t cb_getline(cbuffer_t *cb, char *delim, char *buff, size_t size);

#endif
