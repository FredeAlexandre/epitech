/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** Return the data of a node
*/

#include <stdlib.h>
#include "list_int.h"

int list_int_get(list_int_t *list, int index)
{
    list_int_node_t *node = list->head;
    int i = 0;

    while (node != NULL) {
        if (i == index) return node->data;
        node = node->next;
        i++;
    }
    return 0;
}
