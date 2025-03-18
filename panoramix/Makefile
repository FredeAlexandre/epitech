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

SRC   		=	druid.c		\
				potion.c	\
				threads.c	\
				villager.c	\

OBJ			=	$(SRC:.c=.o)
OBJM		=	$(MAIN:.c=.o)

OUT			=	panoramix

CFLAGS		=	-fno-builtin -W -Wall -I./include -Wextra -Werror

all:		$(OUT)

$(OUT): $(OBJ) $(OBJM)
				$(CC) $(OBJ) $(OBJM) -o $(OUT) $(CFLAGS)

clean:
				rm -f $(OBJ) $(OBJM) *.gcda *.gcno

fclean:		clean
				rm -f $(OUT)

re:			fclean all

dev:
				@make re 1>/dev/null
				@./$(OUT)
				@make fclean 1>/dev/null

.ONESHELL:
lint:		fclean
				@cd "$(CWD)"
				@coding-style . . > /dev/null 2>&1
				@cat coding-style-reports.log
				@rm -f coding-style-reports.log
