/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** Return the data of a node
*/

#include <stdlib.h>
#include "list.h"

void *list_get(list_t *list, int index)
{
    list_node_t *node = list->head;
    int i = 0;

    while (node != NULL) {
        if (i == index) return node->data;
        node = node->next;
        i++;
    }
    return NULL;
}
