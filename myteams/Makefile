##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY: all clean fclean re lint dev

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

CC		=	gcc

MAIN	=	src/main.c

SRC		=	src/cbuffer/cb_consume.c \
			src/cbuffer/cb_create.c \
			src/cbuffer/cb_destroy.c \
			src/cbuffer/cb_getline.c \
			src/cbuffer/cb_read.c \
			src/cbuffer/cb_write.c \
			src/engine/connection_destroy.c \
			src/engine/connection_init.c \
			src/engine/recv_message.c \
			src/engine/send_message.c \
			src/engine/accept_connection.c \
			src/engine/destroy_server.c \
			src/engine/init_server.c \
			src/engine/set_readfds.c \
			src/engine/set_writefds.c \
			src/engine/update_server.c \
			src/engine/clean_connections.c \
			src/engine/request_parser.c \
			src/engine/broadcast.c \
			src/engine/update_reads.c \
			src/engine/update_writes.c \
			src/engine/get_server.c \
			src/routes/router.c \

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

OUT		=	../zappy_server

CFLAGS	=	-Wall -Wextra -I./include

all:	$(OUT)

$(OUT):	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OUT)

re:	fclean all
