/*
** EPITECH PROJECT, 2022
** macros.h
** File description:
** The macros of the library
*/

#ifndef MY_PRG_STRUCTS
    #define MY_PRG_STRUCTS

typedef struct s_item {
    int value;
    int chunk_id;
    struct s_item* next;
    struct s_item* prev;
} item;

typedef struct s_stack {
    int length;
    item *start;
} stack;

#endif
