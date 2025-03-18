/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "panoramix.h"

void init_potion(potion_t *potion, int size)
{
    sem_init(&potion->queue, 0, 1);
    pthread_mutex_init(&potion->access, NULL);
    potion->remaining = size;
    potion->end_service = 0;
    potion->asking = 0;
}

void destroy_potion(potion_t *potion)
{
    sem_destroy(&potion->queue);
    pthread_mutex_destroy(&potion->access);
}
