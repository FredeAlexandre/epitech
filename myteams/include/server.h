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
#define OUT_BUFFER_SIZE 1024

#define MAX_COMMAND_SIZE 512

#define PACKET_END "\n"

typedef struct server_node_s server_node_t;
typedef struct server_s server_t;
typedef struct connection_s connection_t;

struct connection_s {
    int socketfd;
    cbuffer_t *in;
    cbuffer_t *out;
    int delete;
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

void request_parser(const char *prompt);

typedef void (*route_fun)(connection_t *c);

server_t *get_server(server_t* new_server);

void broadcast(const char *message);

void update_writes(server_t *server, fd_set *writefds);
void update_reads(server_t *server, fd_set *readfds);

#endif
