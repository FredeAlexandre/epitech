/*
** EPITECH PROJECT, 2022
** delete.c
** File description:
** Delete a list
*/

#include <stdlib.h>
#include "list.h"

void list_delete(list_t *list)
{
    list_node_t *node = list->head;
    list_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
