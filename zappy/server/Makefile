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
			src/engine/get_graphic.c \
			src/engine/graphic_broadcast.c \
			src/engine/update_reads.c \
			src/engine/update_writes.c \
			src/engine/get_server.c \
			src/routes/router.c \
			src/routes/bots/bots_router.c \
			src/routes/graphicals/graphicals_router.c \
			src/routes/graphicals/msz.c \
			src/routes/graphicals/bct.c \
			src/routes/graphicals/mct.c \
			src/routes/graphicals/tna.c \
			src/routes/graphicals/ppo.c \
			src/routes/graphicals/plv.c \
			src/routes/graphicals/pin.c \
			src/routes/graphicals/sgt.c \
			src/routes/graphicals/quit.c \
			src/utils/get_args.c \
			src/utils/show_help.c \
			src/utils/superprint.c \
			src/zappy/get_zappy.c \
			src/zappy/init_zappy.c \
			src/zappy/destroy_zappy.c \
			src/zappy/add_player.c \
			src/zappy/add_item.c \
			src/zappy/remove_item.c \
			src/zappy/get_amount_inventory.c \
			src/zappy/set_amount_inventory.c \
			src/zappy/get_tile.c \
			src/zappy/get_item_amount.c \
			src/zappy/get_total_item_amount.c \
			src/zappy/get_team.c \
			src/zappy/get_team_of.c \
			src/zappy/update_zappy.c \
			src/zappy/update_ressources.c \
			src/zappy/update_players.c \
			src/zappy/get_item_name.c \
			src/zappy/actions/forward.c \
			src/zappy/actions/right.c \
			src/zappy/actions/left.c \
			src/zappy/actions/look.c \
			src/zappy/actions/inventory.c \
			src/zappy/actions/broadcast.c \
			src/zappy/actions/connect_nbr.c \
			src/zappy/actions/fork.c \
			src/zappy/actions/eject.c \
			src/zappy/actions/take.c \
			src/zappy/actions/set.c \

OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

OUT		=	../zappy_server

CFLAGS	=	-Wall -Wextra -I./include

all:	$(OUT)

$(OUT):	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OUT)

re:	fclean all
