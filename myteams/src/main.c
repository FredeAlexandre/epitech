/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** The main of the server
*/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "server.h"
#include "cbuffer.h"

int is_running(int stop)
{
    static int running = 1;

    if (stop) running = 0;
    return running;
}

void stop_app(int sig)
{
    (void)sig;
    is_running(1);
}

int get_port(int argc, const char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./myteams_server port\n");
        return -1;
    }

    for (size_t i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            fprintf(stderr, "Invalid port number\n");
            return -1;
        }
    }
    return atoi(argv[1]);
}

int main(int argc, const char** argv)
{
    if (init_server(get_port(argc, argv)) == -1) {
        return 84;
    }

    signal(SIGINT, stop_app);

    while (is_running(0)) {
        update_server();
        router();
    }
    destroy_server();
    return 0;
}
