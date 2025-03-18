/*
** EPITECH PROJECT, 2022
** sort.c
** File description:
** Sort nodes from a list with a comparator function
*/

#include <stdlib.h>
#include "list.h"

void list_sort_compare(CMP_LIST, list_node_t *node, list_node_t *next)
{
    void *tmp = NULL;

    if (comparator(node->data, next->data) > 0) {
        tmp = node->data;
        node->data = next->data;
        next->data = tmp;
    }
}

void list_sort(list_t *list, CMP_LIST)
{
    list_node_t *node = list->head;
    list_node_t *next = NULL;

    while (node != NULL) {
        next = node->next;
        while (next != NULL) {
            list_sort_compare(comparator, node, next);
            next = next->next;
        }
        node = node->next;
    }
}
