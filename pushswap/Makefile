##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY:	all compile clean fclean re lint

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SRC_MAIN	=	main.c

SRC_FILES   =   swap.c								\
				rotation.c							\
				rrotation.c							\
				move.c								\
				get_mid.c							\
				print_status.c						\
				sort.c								\
				create_stack.c						\
				free_stack.c						\
				add_item.c							\
				fill_stack_a.c						\
				print_divider.c						\
				set_sorted.c						\
				chunk_length.c						\
				chunk_start.c						\
				chunk_stop.c						\
				create_chunk.c						\
				chunk_amount.c						\
				swapif.c							\
				global.c							\

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)
OBJ			=	$(SRC_FILES:.c=.o)

OUT			=	push_swap

CFLAGS		=	-fno-builtin -W -Wall
CLIBS		=	-L./libs/string -lmystring

all:		compile

lib_compile:
				make -C libs/string/src

compile:	lib_compile
				$(CC) $(SRC_FILES) $(SRC_MAIN) -c
				$(CC) $(OBJ) $(OBJ_MAIN) -o $(OUT) $(CLIBS)

clean:
				make -C libs/string/src clean
				rm -f $(OBJ) $(OBJ_MAIN)

fclean:		clean
				make -C libs/string/src fclean
				rm -f $(OUT)

re:			fclean all

.ONESHELL:
lint:		fclean
				@cd "$(CWD)"
				@coding-style . . > /dev/null 2>&1
				@cat coding-style-reports.log
				@rm -f coding-style-reports.log

dev:		re
				make -C libs/string/src fclean
				@make clean > /dev/null 2>&1
