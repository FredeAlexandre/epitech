/*
** EPITECH PROJECT, 2022
** to_array.c
** File description:
** Make an array from a list
*/

#include <stdlib.h>
#include "list.h"

void **list_to_array(list_t *list)
{
    void **array = malloc(sizeof(void *) * (list->size + 1));
    list_node_t *node = list->head;
    int i = 0;

    while (node != NULL) {
        array[i] = node->data;
        node = node->next;
        i++;
    }
    array[i] = NULL;
    return array;
}
