/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** All list functions and structs
*/

#ifndef _MYFTP_UTILS_LIST_
    #define _MYFTP_UTILS_LIST_

    #define CMP_LIST int (*comparator)(void *, void *)

typedef struct list_node_s {
    void *data;
    struct list_node_s *next;
    struct list_node_s *prev;
} list_node_t;

typedef struct list_s {
    list_node_t *head;
    list_node_t *tail;
    int size;
} list_t;

list_t *list_create(void);
void list_delete(list_t *list);
void list_add(list_t *list, void *data);
void list_remove(list_t *list, list_node_t *node);
void list_remove_at(list_t *list, int index);
void *list_get(list_t *list, int index);
int list_get_size(list_t *list);
void list_swap(list_t *list, int index1, int index2);
void list_sort(list_t *list, int (*cmp)(void *, void *));
void **list_to_array(list_t *list);
list_t *list_from_array(void **array);

#endif
