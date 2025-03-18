/*
** EPITECH PROJECT, 2022
** to_array.c
** File description:
** Make an array from a list
*/

#include <stdlib.h>
#include "list_int.h"

int *list_int_to_array(list_int_t *list)
{
    int *array = malloc(sizeof(int) * (list->size + 1));
    list_int_node_t *node = list->head;
    int i = 0;

    while (node != NULL) {
        array[i] = node->data;
        node = node->next;
        i++;
    }
    array[i] = 0;
    return array;
}
