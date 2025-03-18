/*
** EPITECH PROJECT, 2022
** swap.c
** File description:
** Swap two nodes in a list
*/

#include <stdlib.h>
#include "list_int.h"

void list_int_swap(list_int_t *list, int index1, int index2)
{
    if (index1 == index2) return;
    list_int_node_t *node1 = list->head;
    list_int_node_t *node2 = list->head;
    int i = 0;
    while (node1 != NULL) {
        if (i == index1) break;
        node1 = node1->next;
        i++;
    }
    i = 0;
    while (node2 != NULL) {
        if (i == index2) break;
        node2 = node2->next;
        i++;
    }
    if (node1 == NULL || node2 == NULL) return;
    int tmp = node1->data;
    node1->data = node2->data;
    node2->data = tmp;
}
