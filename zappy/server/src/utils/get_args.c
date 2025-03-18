/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <string.h>
#include <stdio.h>

#include "server.h"

int is_help(int argc, const char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0)
            return 1;
    }
    return 0;
}

void set_port(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            if (i + 1 >= argc)
                break;
            args->port = atoi(argv[i + 1]);
            return;
        }
    }
    args->port = 4242;
}

void set_width(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-x") == 0) {
            if (i + 1 >= argc)
                break;
            args->width = atoi(argv[i + 1]);
            return;
        }
    }
    args->width = 10;
}

void set_height(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-y") == 0) {
            if (i + 1 >= argc)
                break;
            args->height = atoi(argv[i + 1]);
            return;
        }
    }
    args->height = 10;
}

void set_clients_nb_max(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 >= argc)
                break;
            args->clients_nb_max = atoi(argv[i + 1]);
            return;
        }
    }
    args->clients_nb_max = 3;
}

void set_freq(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 >= argc)
                break;
            args->freq = atoi(argv[i + 1]);
            return;
        }
    }
    args->freq = 100;
}

void set_names(int argc, const char **argv, args_t *args)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 >= argc)
                break;
            args->first_name_id = i + 1;
            while (i + 1 < argc && argv[i + 1][0] != '-')
                i++;
            args->last_name_id = i;
            return;
        }
    }
    args->first_name_id = -1;
    args->last_name_id = -1;
}

const args_setter_t args_setters[6] = {
    set_port,
    set_width,
    set_height,
    set_clients_nb_max,
    set_freq,
    set_names
};

int get_args(int argc, const char **argv, args_t *args)
{
    if (is_help(argc, argv)) {
        show_usage(0);
        return 1;
    }

    for (size_t i = 0; i < 6; i++) args_setters[i](argc, argv, args);

    if (args->width < 10 || args->width > 30) {
        fprintf(stderr, "-x option only accepts integer values between 10 and 30\n\n");
        show_usage(1);
        return -1;
    }
    
    if (args->height < 10 || args->height > 30) {
        fprintf(stderr, "-y option only accepts integer values between 10 and 30\n\n");
        show_usage(1);
        return -1;
    }
    
    if (args->clients_nb_max < 1) {
        fprintf(stderr, "-c option only accepts integer values greater or equal to 1\n\n");
        show_usage(1);
        return -1;
    }

    if (args->port < 0) {
        fprintf(stderr, "-p option only accepts valid ports\n\n");
        show_usage(1);
        return -1;
    }

    if (args->freq < 2 || args->freq > 10000) {
        fprintf(stderr, "-f option only accepts integer values between 2 and 10000\n\n");
        show_usage(1);
        return -1;
    }

    return 0;
}
