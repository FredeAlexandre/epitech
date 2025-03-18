/*
** EPITECH PROJECT, 2022
** myftp.h
** File description:
** All function for program
*/

#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>

void get_227(uint32_t ip, int port, char *result)
{
    sprintf(result, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).",
        (ip >> 24) & 0xFF,
        (ip >> 16) & 0xFF,
        (ip >> 8) & 0xFF,
        ip & 0xFF,
        port / 256,
        port % 256
    );
}
