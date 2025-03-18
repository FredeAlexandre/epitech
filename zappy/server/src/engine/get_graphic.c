/*
** EPITECH PROJECT, 2022
** get_server.c
** File description:
** Save the server globaly
*/

#include "server.h"

char *get_graphic(char *graphic_ptr)
{
    static char *ptr = NULL;

    if (graphic_ptr != NULL) ptr = graphic_ptr;

    return ptr;
}
