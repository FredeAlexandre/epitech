/*
** EPITECH PROJECT, 2022
** myftp.h
** File description:
** All function for program
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "utils/utils.h"

#ifndef _MYFTP_
    #define _MYFTP_

    #define LISTEN_QUEUE 3

    #define READ_BUFFER 4096

    #define SERVER_PREFIX "[SERVER] "

    #define SOCKET_CLOSED -1

    #define CHECKING 0
    #define STOPPING 1

    #define DATA_NONE 0
    #define DATA_PASSIVE 1
    #define DATA_ACTIVE 2

typedef struct client_s {
    int session_id;
    int command_socket;
    int data_socket;
    int data_type;
    int root_socket;
    struct sockaddr_in client;
    char *username;
    char *password;
    int is_auth;
    char *pwd;
    char *command;
} client_t;

    #define AS_CLIENT(x) ((client_t *)x)

void init(int argc, char *const *const argv, list_t **clients, int *main);

void clean_client(client_t *client);
void end(list_t *clients, int main_socket);

void run_server(list_t *clients, int main_socket);

int handle_command(client_t *client);

void router(client_t *client);
void handle_cdup(client_t *client);
void handle_cwd(client_t *client);
void handle_dele(client_t *client);
void handle_help(client_t *client);
void handle_list(client_t *client);
void handle_noop(client_t *client);
void handle_pass(client_t *client);
void handle_pasv(client_t *client);
void handle_port(client_t *client);
void handle_pwd(client_t *client);
void handle_quit(client_t *client);
void handle_retr(client_t *client);
void handle_stor(client_t *client);
void handle_type(client_t *client);
void handle_user(client_t *client);

int setdata(client_t *client);
void show_files(client_t *client);
int retr_check(client_t *client);
void retr(client_t *client);
void stor(client_t *client);
int handle_guard(client_t *client);

    #define REPLY_150 "150 File status okay; about to open data connection."
    #define REPLY_200 "200 Command okay."
    #define REPLY_214 "214 Help message."
    #define REPLY_220 "220 Service ready for new user."
    #define REPLY_221 "221 Service closing control connection."
    #define REPLY_226 "226 Closing data connection."
    #define REPLY_230 "230 User logged in, proceed."
    #define REPLY_250 "250 Requested file action okay, completed."
    #define REPLY_331 "331 User name okay, need password."
    #define REPLY_332 "332 Need account for login."
    #define REPLY_425 "425 Can't open data connection."
    #define REPLY_450 "450 Requested file action not taken."
    #define REPLY_500 "500 Syntax error, command unrecognized."
    #define REPLY_501 "501 Syntax error in parameters or arguments."
    #define REPLY_503 "503 Bad sequence of commands."
    #define REPLY_504 "504 Command not implemented for that parameter."
    #define REPLY_530 "530 Not logged in."
    #define REPLY_550 "550 Requested action not taken."


int list_files_guard(void);

#endif
