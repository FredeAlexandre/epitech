/*
** EPITECH PROJECT, 2022
** add.c
** File description:
** Add data on list
*/

#include <stdlib.h>
#include "list_int.h"

void list_int_add(list_int_t *list, int data)
{
    list_int_node_t *node = malloc(sizeof(list_int_node_t));

    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail != NULL)
        list->tail->next = node;
    list->tail = node;
    if (list->head == NULL)
        list->head = node;
    list->size++;
}
