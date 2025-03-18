/*
** EPITECH PROJECT, 2022
** create.c
** File description:
** Create a new list
*/

#include <stdlib.h>
#include "list.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
