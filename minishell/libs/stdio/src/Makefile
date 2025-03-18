##
## EPITECH PROJECT, 2022
## Makefile lib
## File description:
## Just the makefile to compile the lib
##

.PHONY:	all build clean flcean re lint dev unit_tests tests_run

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SRC		=		my_puts.c								\

OBJ		=		$(SRC:.c=.o)

LIB		=		../libmystdio.a

TEST	=		./test
TESTS	=		tests/test_puts.c						\

CFLAGS	=		-fno-builtin -W -Wall -I../include
CLIBS		=	-L../../string -lmystring

CC		=		gcc $(CFLAGS)

all:		build

lib_compile:
				make -C ../../string/src

build:		$(OBJ)
				$(CC) $(CFLAGS) $(SRC) -c
				ar rc $(LIB) $(OBJ)

clean:
				make -C ../../string/src clean
				rm -f $(OBJ) $(TEST) *.gcno *.gcda

fclean:		clean
				make -C ../../string/src fclean
				rm -f $(LIB)

re:			fclean build

.ONESHELL:
lint:		fclean
				@cd "$(CWD)/.."
				@mv src/tests tests
				@echo "======= STRING LINTER ======"
				@coding-style . . > /dev/null 2>&1
				@cat coding-style-reports.log
				@echo "============================"
				@rm -f coding-style-reports.log
				@mv tests src/tests

dev:		coverage
				@make fclean > /dev/null 2>&1

unit_tests:	lib_compile
				@$(CC) $(CFLAGS) -o $(TEST) $(SRC) $(TESTS) $(CLIBS) -lcriterion

coverage:	lib_compile
				@$(CC) $(CFLAGS) -o $(TEST) $(SRC) \
					$(TESTS) $(CLIBS) -lcriterion --coverage
				@echo "======== STRING DEV ========"
				@$(TEST)
				@gcovr --exclude tests/
				@echo "============================"

tests_run:	unit_tests
				@$(TEST)
