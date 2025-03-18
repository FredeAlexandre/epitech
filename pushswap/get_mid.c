/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/global.h"

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quicksort(int *arr, int low, int high)
{
    if (low >= high) return;
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

int *create_arr(item *start, int len)
{
    int *arr = malloc(sizeof(int) * len);
    item *actual = start;
    for (int i = 0; i < len; i++) {
        arr[i] = actual->value;
        actual = actual->next;
    }
    return arr;
}

int get_mid(item *start, item *stop, int len)
{
    int *arr = create_arr(start, len);
    quicksort(arr, 0, len - 1);
    int i = arr[len / 2];
    free(arr);
    return i;
}
