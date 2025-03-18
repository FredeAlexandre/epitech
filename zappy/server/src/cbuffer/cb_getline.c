/*
** EPITECH PROJECT, 2022
** cb_read.h
** File description:
** Read the buffer from last cosumed byte
*/

#include <string.h>
#include <strings.h>

#include "cbuffer.h"

size_t cb_getline(cbuffer_t *cb, char *delim, char *buff, size_t size)
{
    char buffer[MAX_CBUFFER_SIZE];
    bzero(buffer, MAX_CBUFFER_SIZE);

    cb_read(cb, buffer, MAX_CBUFFER_SIZE);
    char *end = strstr(buffer, delim);
    if (end == NULL) return 0;
    size_t len = (end - buffer) / sizeof(char);
    if ((len + 1) > size) return 0;
    cb_consume(cb, buff, len);
    buff[len] = '\0';
    cb_consume(cb, NULL, strlen(delim));
    return len;
}
