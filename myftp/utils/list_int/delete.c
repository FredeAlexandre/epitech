/*
** EPITECH PROJECT, 2022
** delete.c
** File description:
** Delete a list
*/

#include <stdlib.h>
#include "list_int.h"

void list_int_delete(list_int_t *list)
{
    list_int_node_t *node = list->head;
    list_int_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
