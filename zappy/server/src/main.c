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

#include "zappy.h"
#include "cbuffer.h"

static int is_running(int stop)
{
    static int running = 1;

    if (stop) running = 0;
    return running;
}

static void stop_app(int sig)
{
    (void)sig;
    is_running(1);
}

int main(int argc, const char** argv)
{
    args_t args;
    int result = get_args(argc, argv, &args);
    if (result == 1) return 0;
    if (result == -1) return 84;

    if (init_zappy(argv, &args) == -1) return 84;

    signal(SIGINT, stop_app);

    while (is_running(0)) {
        update_server();
        router();
        update_zappy();
    }

    destroy_zappy();

    return 0;
}
