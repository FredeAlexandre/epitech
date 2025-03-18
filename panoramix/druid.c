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

void *druid(void *arg)
{
    druid_t *state = (druid_t *)arg;
    printf("Druid: I'm ready... but sleepy...\n");

    while (!(state->refills <= 0 || state->potion->end_service == 1)) {
        if (state->potion->asking == 0) continue;
        pthread_mutex_lock(&state->potion->access);
        state->refills--;
        printf(D1 D2 D3, state->refills);
        state->potion->remaining = state->size;
        pthread_mutex_unlock(&state->potion->access);
    }

    state->potion->end_service = 1;

    if (state->refills <= 0)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");

    free(state);
    return NULL;
}
