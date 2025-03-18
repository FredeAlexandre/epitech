/*
** EPITECH PROJECT, 2022
** remove.c
** File description:
** Remove an item on list
*/

#include <stdlib.h>
#include "list.h"

void list_remove(list_t *list, list_node_t *node)
{
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    free(node);
    list->size--;
}
