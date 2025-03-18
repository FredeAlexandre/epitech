/*
** EPITECH PROJECT, 2022
** create.c
** File description:
** Create a new list
*/

#include <stdlib.h>
#include "list_int.h"

list_int_t *list_int_create(void)
{
    list_int_t *list = malloc(sizeof(list_int_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
