/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function
*/

#include "myftp.h"

#include <signal.h>

int is_running(int stop)
{
    static int running = 1;

    if (stop == 1)
        running = 0;
    return running;
}

void sigint_handler(int sig)
{
    (void)sig;
    is_running(STOPPING);
}

int main(int argc, char *const *const argv)
{
    list_t *clients = NULL;
    int main_socket = 0;

    signal(SIGINT, &sigint_handler);

    init(argc, argv, &clients, &main_socket);

    while (is_running(CHECKING)) {
        run_server(clients, main_socket);
    }

    end(clients, main_socket);

    return 0;
}
