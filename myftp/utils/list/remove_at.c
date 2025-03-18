/*
** EPITECH PROJECT, 2022
** remove_at.c
** File description:
** Remove an item on list at specific index
*/

#include <stdlib.h>
#include "list.h"

void list_remove_at(list_t *list, int index)
{
    list_node_t *node = list->head;
    int i = 0;

    while (node != NULL) {
        if (i == index) return list_remove(list, node);
        node = node->next;
        i++;
    }
}
