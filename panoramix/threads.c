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

void init_threads(pthread_t *threads, arguments_t *args, potion_t *potion)
{
    for (int i = 0; i < args->villagers; i++) {
        villager_t *state = malloc(sizeof(villager_t));
        state->id = i;
        state->fights = args->fights;
        state->potion = potion;
        pthread_create(&threads[i], NULL, villager, state);
    }
    druid_t *state = malloc(sizeof(druid_t));
    state->refills = args->refills;
    state->potion = potion;
    state->size = args->size;
    pthread_create(&threads[args->villagers], NULL, druid, state);
}

void destroy_threads(pthread_t *threads, arguments_t *args, potion_t *potion)
{
    for (int i = 0; i < args->villagers; i++)
        pthread_join(threads[i], NULL);
    potion->end_service = 1;
    pthread_join(threads[args->villagers], NULL);
}
