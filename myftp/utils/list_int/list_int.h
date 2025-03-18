/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** All list functions and structs
*/

#ifndef _MYFTP_UTILS_LIST_INT_
    #define _MYFTP_UTILS_LIST_INT_

    #define CMP_LIST_INT int (*comparator)(int, int)
    #define INTCMP CMP_LIST_INT

typedef struct list_int_node_s {
    int data;
    struct list_int_node_s *next;
    struct list_int_node_s *prev;
} list_int_node_t;

typedef struct list_int_s {
    list_int_node_t *head;
    list_int_node_t *tail;
    int size;
} list_int_t;

list_int_t *list_int_create(void);
void list_int_delete(list_int_t *list);
void list_int_add(list_int_t *list, int data);
void list_int_remove(list_int_t *list, list_int_node_t *node);
void list_int_remove_at(list_int_t *list, int index);
int list_int_get(list_int_t *list, int index);
int list_int_get_size(list_int_t *list);
void list_int_swap(list_int_t *list, int index1, int index2);
void list_int_sort(list_int_t *list, int (*cmp)(int, int));
int *list_int_to_array(list_int_t *list);
list_int_t *list_int_from_array(int *array);

#endif
