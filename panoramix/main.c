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

int parse_argument(const char *arg)
{
    int result = atoi(arg);
    if (result <= 0) {
        fprintf(stderr, USAGE_1 USAGE_2);
        fprintf(stderr, "Values must be >0.\n");
        exit(84);
    }
    return result;
}

int main_guard(int argc)
{
    if (argc != 5) {
        fprintf(stderr, USAGE_1 USAGE_2);
        return -1;
    }
    return 0;
}

int main(int argc, const char **argv)
{
    potion_t potion;
    arguments_t args;
    if (main_guard(argc) == -1) return 84;
    args.villagers = parse_argument(argv[1]);
    args.size = parse_argument(argv[2]);
    args.fights = parse_argument(argv[3]);
    args.refills = parse_argument(argv[4]);
    init_potion(&potion, args.size);
    pthread_t *threads = malloc(sizeof(pthread_t) * (args.villagers + 1));
    init_threads(threads, &args, &potion);
    destroy_threads(threads, &args, &potion);
    free(threads);
    destroy_potion(&potion);
    return 0;
}
