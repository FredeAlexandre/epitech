##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY:	all $(OUT) clean fclean re lint

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

CC			=	gcc

MAIN		=	main.c

SRC   		=	utils/list/add.c \
				utils/list/create.c \
				utils/list/delete.c \
				utils/list/get.c \
				utils/list/get_size.c \
				utils/list/remove.c \
				utils/list/remove_at.c \
				utils/list/sort.c \
				utils/list/swap.c \
				utils/list/to_array.c \
				utils/list_int/add.c \
				utils/list_int/create.c \
				utils/list_int/delete.c \
				utils/list_int/get.c \
				utils/list_int/get_size.c \
				utils/list_int/remove.c \
				utils/list_int/remove_at.c \
				utils/list_int/sort.c \
				utils/list_int/swap.c \
				utils/list_int/to_array.c \
				utils/send_command.c \
				utils/get_227.c \
				utils/extract_ip.c \
				routes/handle_cdup.c \
				routes/handle_cwd.c \
				routes/handle_dele.c \
				routes/handle_help.c \
				routes/handle_list.c \
				routes/handle_noop.c \
				routes/handle_pass.c \
				routes/handle_pasv.c \
				routes/handle_port.c \
				routes/handle_pwd.c \
				routes/handle_quit.c \
				routes/handle_retr.c \
				routes/handle_stor.c \
				routes/handle_type.c \
				routes/handle_user.c \
				helpers/setdata.c \
				helpers/show_files.c \
				helpers/handle_guard.c \
				helpers/retr.c \
				helpers/stor.c \
				init.c \
				end.c \
				run_server.c \
				handle_command.c \
				router.c \

OBJ			=	$(SRC:.c=.o)
OBJM		=	$(MAIN:.c=.o)

OUT			=	myftp

CFLAGS		=	-fno-builtin -W -Wall

all:		$(OUT)

$(OUT): $(OBJ) $(OBJM)
				$(CC) $(OBJ) $(OBJM) -o $(OUT) $(CFLAGS)

clean:
				rm -f $(OBJ) $(OBJM) *.gcda *.gcno

fclean:		clean
				rm -f $(OUT)

re:			fclean all

.ONESHELL:
lint:		fclean
				@cd "$(CWD)"
				@coding-style . . > /dev/null 2>&1
				@cat coding-style-reports.log
				@rm -f coding-style-reports.log
