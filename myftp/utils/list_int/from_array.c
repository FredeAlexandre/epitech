/*
** EPITECH PROJECT, 2022
** from_array.c
** File description:
** Make a list from an array
*/

#include <stdlib.h>
#include "list_int.h"

list_int_t *list_int_from_array(int *array)
{
    list_int_t *list = list_int_create();
    int i = 0;

    while (array[i] != NULL) {
        list_int_add(list, array[i]);
        i++;
    }
    return list;
}
