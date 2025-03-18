/*
** EPITECH PROJECT, 2022
** myftp.h
** File description:
** All function for program
*/

#include "list/list.h"
#include "list_int/list_int.h"

#ifndef _MYFTP_UTILS_
    #define _MYFTP_UTILS_

void send_command(int fd, char *msg, int from);

void get_227(uint32_t ip, int port, char *result);
int extract_ip(char *ip, struct sockaddr_in* addr);

#endif
