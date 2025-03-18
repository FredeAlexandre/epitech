/*
** EPITECH PROJECT, 2022
** from_array.c
** File description:
** Make a list from an array
*/

#include <stdlib.h>
#include "list.h"

list_t *list_from_array(void **array)
{
    list_t *list = list_create();
    int i = 0;

    while (array[i] != NULL) {
        list_add(list, array[i]);
        i++;
    }
    return list;
}
