/*
** EPITECH PROJECT, 2022
** log.c
** File description:
** Simple log for the boilerplate
*/

#include <stdio.h>

#include "server.h"

void show_usage(int error)
{
    FILE *stream = error ? stderr : stdout;
    fprintf(stream, "USAGE: ./zappy_server -p port -x width -y height -n ");
    fprintf(stream, "name1 name2 ... -c clientsNb -f freq\n");
    fprintf(stream, "\tport\t\tis the port number\n");
    fprintf(stream, "\twidth\t\tis the width of the world\n");
    fprintf(stream, "\theight\t\tis the height of the world\n");
    fprintf(stream, "\tnameX\t\tis the name of the team X\n");
    fprintf(stream, "\tclientsNb\tis the number of authorized clients per team\n");
    fprintf(stream, "\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
}
