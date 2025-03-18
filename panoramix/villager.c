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

void ask(villager_t *state)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
    state->id);
    state->potion->asking = 1;
    pthread_mutex_unlock(&state->potion->access);
    while (state->potion->remaining <= 0) {}
    state->potion->asking = 0;
    pthread_mutex_lock(&state->potion->access);
}

int drink(villager_t *state)
{
    sem_wait(&state->potion->queue);
    pthread_mutex_lock(&state->potion->access);
    if (state->potion->remaining <= 0 && state->potion->end_service == 1) {
        pthread_mutex_unlock(&state->potion->access);
        sem_post(&state->potion->queue);
        return -1;
    }

    if (state->potion->remaining <= 0) ask(state);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    state->id,
    state->potion->remaining);
    state->potion->remaining--;
    pthread_mutex_unlock(&state->potion->access);
    sem_post(&state->potion->queue);
    return 0;
}

void *villager(void *arg)
{
    villager_t *state = (villager_t *)arg;
    printf("Villager %d: Going into battle!\n", state->id);

    for (int i = 0; i < state->fights; i++) {
        if (drink(state) < 0) break;
        printf("Villager %d: Take that roman scum! Only %d left.\n", state->id,
        state->fights - i - 1);
    }

    printf("Villager %d: I'm going to sleep now.\n", state->id);
    free(state);
    return NULL;
}
