/*
** EPITECH PROJECT, 2022
** add.c
** File description:
** Add data on list
*/

#include <stdlib.h>
#include "list.h"

void list_add(list_t *list, void *data)
{
    list_node_t *node = malloc(sizeof(list_node_t));

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
