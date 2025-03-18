/*
** EPITECH PROJECT, 2022
** myftp.h
** File description:
** All function for program
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void send_command(int fd, char *msg, int from)
{
    if (from > 0) printf("[SESSION %d] -> \"%s\"\n", from, msg);
    write(fd, msg, strlen(msg));
    write(fd, "\r\n", 2);
}
