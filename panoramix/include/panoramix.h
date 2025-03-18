/*
** EPITECH PROJECT, 2022
** panoramix.h
** File description:
** All function for program
*/

#include <pthread.h>
#include <semaphore.h>

#ifndef _PANORAMIX_
    #define _PANORAMIX_

    #define USAGE_1 "USAGE: ./panoramix <nb_villagers> "
    #define USAGE_2 "<pot_size> <nb_fights> <nb_refills>\n"

    #define D1 "Druid: Ah! Yes, yes, I'm awake! "
    #define D2 "Working on it! Beware I can only make "
    #define D3 "%d more refills after this one.\n"

typedef struct potion_s potion_t;
typedef struct villager_s villager_t;
typedef struct druid_s druid_t;
typedef struct arguments_s arguments_t;

struct potion_s {
    sem_t queue;
    pthread_mutex_t access;
    int remaining;
    int end_service;
    int asking;
};

struct villager_s {
    potion_t *potion;
    int id;
    int fights;
};

struct druid_s {
    potion_t *potion;
    int refills;
    int size;
};

struct arguments_s {
    int villagers;
    int fights;
    int refills;
    int size;
};

void *druid(void *arg);
void *villager(void *arg);

void init_potion(potion_t *potion, int size);
void destroy_potion(potion_t *potion);

void init_threads(pthread_t *threads, arguments_t *args, potion_t *potion);
void destroy_threads(pthread_t *threads, arguments_t *args, potion_t *potion);

#endif
