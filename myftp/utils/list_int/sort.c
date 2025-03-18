/*
** EPITECH PROJECT, 2022
** sort.c
** File description:
** Sort nodes from a list with a comparator function
*/

#include <stdlib.h>
#include "list_int.h"

void list_int_sort_compare(INTCMP, list_int_node_t *node, list_int_node_t *next)
{
    int tmp = 0;

    if (comparator(node->data, next->data) > 0) {
        tmp = node->data;
        node->data = next->data;
        next->data = tmp;
    }
}

void list_int_sort(list_int_t *list, CMP_LIST_INT)
{
    list_int_node_t *node = list->head;
    list_int_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        while (next != NULL) {
            list_int_sort_compare(comparator, node, next);
            next = next->next;
        }
        node = node->next;
    }
}
