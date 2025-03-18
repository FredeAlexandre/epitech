/*
** EPITECH PROJECT, 2022
** server.h
** File description:
** All functions used by the server
*/

#include <sys/select.h>
#include "cbuffer.h"

#ifndef _ZAPPY_SERVER_
#define _ZAPPY_SERVER_

#define QUEU_SIZE 10

#define IN_BUFFER_SIZE 512
#define OUT_BUFFER_SIZE 16384

#define MAX_COMMAND_SIZE 512

#define PACKET_END "\n"

#define IS_GRAPHIC get_graphic(NULL)

typedef struct server_node_s server_node_t;
typedef struct server_s server_t;
typedef struct connection_s connection_t;

struct connection_s {
    int socketfd;
    cbuffer_t *in;
    cbuffer_t *out;
    int delete;
    
    void* player;
};

struct server_node_s {
    connection_t *connection;
    struct server_node_s *next;
    struct server_node_s *prev;
};

struct server_s {
    int socketfd;
    server_node_t *head;
    server_node_t *tail;
};

connection_t *connection_init(int socketfd);
void connection_destroy(connection_t *connection);

size_t send_message(connection_t *connection, const char *message);
size_t recv_message(connection_t *connection, char *buffer, size_t size);

int init_server(int port);
void destroy_server(void);
void update_server(void);
void clean_connections(server_t *server);

void accept_connection(server_t *server);

int set_readfds(server_t *server, fd_set *readfds);
int set_writefds(server_t *server, fd_set *writefds);

void router(void);
void bots_router(connection_t *connection, const char *command);

void graphicals_router(connection_t *connection, char *command);

typedef void (*route_fun)(connection_t *c);

server_t *get_server(server_t* new_server);

char *get_graphic(char *graphic_ptr);
void graphic_broadcast(const char *message);

void update_writes(server_t *server, fd_set *writefds);
void update_reads(server_t *server, fd_set *readfds);

void superprint(const char *str, size_t size);

typedef struct args_s args_t;

struct args_s {
    int port;
    int width;
    int height;
    int clients_nb_max;
    int freq;
    int first_name_id;
    int last_name_id;
};

void show_usage(int error);
int get_args(int argc, const char **argv, args_t *args);

void set_port(int argc, const char **argv, args_t *args);
void set_width(int argc, const char **argv, args_t *args);
void set_height(int argc, const char **argv, args_t *args);
void set_clients_nb_max(int argc, const char **argv, args_t *args);
void set_freq(int argc, const char **argv, args_t *args);
void set_names(int argc, const char **argv, args_t *args);

typedef void (*args_setter_t)(int, const char **, args_t *);

#endif
