/*
** EPITECH PROJECT, 2022
** get_size.c
** File description:
** Return the size of the list
*/

#include <stdlib.h>
#include "list_int.h"

int list_int_get_size(list_int_t *list)
{
    return list->size;
}
