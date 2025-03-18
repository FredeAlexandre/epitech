/*
** EPITECH PROJECT, 2022
** functions.h
** File description:
** The functions of the library
*/

#include "structs.h"

#ifndef MY_PRG_FUNCTIONS
    #define MY_PRG_FUNCTIONS

stack *create_stack(void);
void free_stack(stack *s);
void add_item(int v, stack *stack);

void fill_stack_a(int argc, char **argv);

void swap(stack *s);
void rotation(stack *s);
void allrotation(stack *s);
void rrotation(stack *s);
void allrrotation(stack *s);
void move(stack *s1);

void sort(void);
void print_status(char *action);
void print_divider(void);
void set_sorted(void);

void swapif(stack *s, item *start, item *stop);

int is_lastchunk(stack *s, int id);
item *chunk_start(stack *s, int id, int last);
item *chunk_stop(stack *s, int id, int last);
int chunk_length(stack *s, int id);
int chunk_amount(stack *s);
void create_chunk(stack *s, item *start, item *stop, int mid);

int get_mid(item *start, item *stop, int len);

stack *stack_a(stack *si);
stack *stack_b(stack *si);
int v_enabled(int i);
int chunk_id(int i);
int first_action(int i);

#endif
