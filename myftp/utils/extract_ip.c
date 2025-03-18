/*
** EPITECH PROJECT, 2022
** myftp.h
** File description:
** All function for program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>

int extract_ip(char *ip, struct sockaddr_in* addr)
{
    int h1 = atoi(strtok(ip, ","));
    int h2 = atoi(strtok(NULL, ","));
    int h3 = atoi(strtok(NULL, ","));
    int h4 = atoi(strtok(NULL, ","));
    int p1 = atoi(strtok(NULL, ","));
    int p2 = atoi(strtok(NULL, ","));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(p1 * 256 + p2);
    char ip_str[16];
    snprintf(ip_str, 16, "%d.%d.%d.%d", h1, h2, h3, h4);
    if (inet_pton(AF_INET, ip_str, &addr->sin_addr) != 1) {
        return -1;
    }
    return 0;
}
