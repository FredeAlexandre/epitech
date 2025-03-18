/*
** EPITECH PROJECT, 2022
** get_size.c
** File description:
** Return the size of the list
*/

#include <stdlib.h>
#include "list.h"

int list_get_size(list_t *list)
{
    return list->size;
}
