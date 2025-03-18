##
## EPITECH PROJECT, 2022
## Makefile lib
## File description:
## Just the makefile to compile the lib
##

.PHONY:	all build clean flcean re lint dev unit_tests tests_run

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SRC		=		my_strlen.c								\
				my_memccpy.c							\
				my_memchr.c								\
				my_memcmp.c								\
				my_memcpy.c								\
				my_memmove.c							\
				my_memset.c								\
				my_strcat.c								\
				my_strchr.c								\
				my_strcmp.c								\
				my_strcpy.c								\
				my_strcspn.c							\
				my_strdup.c								\
				my_strncat.c							\
				my_strncmp.c							\
				my_strncpy.c							\
				my_strndup.c							\
				my_strpbrk.c							\
				my_strrchr.c							\
				my_strspn.c								\
				my_strstr.c								\
				my_strtok.c								\

OBJ		=		$(SRC:.c=.o)

LIB		=		../libmystring.a

TEST	=		./test
TESTS	=		tests/test_strlen.c						\
				tests/test_memccpy.c					\
				tests/test_memchr.c						\
				tests/test_memcmp.c						\
				tests/test_memcpy.c						\
				tests/test_memmove.c					\
				tests/test_memset.c						\
				tests/test_strcat.c						\
				tests/test_strchr.c						\
				tests/test_strcmp.c						\
				tests/test_strcpy.c						\
				tests/test_strcspn.c					\
				tests/test_strdup.c						\
				tests/test_strncat.c					\
				tests/test_strncmp.c					\
				tests/test_strncpy.c					\
				tests/test_strndup.c					\
				tests/test_strpbrk.c					\
				tests/test_strrchr.c					\
				tests/test_strspn.c						\
				tests/test_strstr.c						\
				tests/test_strtok.c						\

CFLAGS	=		-fno-builtin -W -Wall -I../include

CC		=		gcc $(CFLAGS)

all:		build

build:		$(OBJ)
				$(CC) $(SRC) -c
				ar rc $(LIB) $(OBJ)

clean:
				rm -f $(OBJ) $(TEST) *.gcno *.gcda

fclean:		clean
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

unit_tests:
				@$(CC) -o $(TEST) $(SRC) $(TESTS) -lcriterion

coverage:
				@$(CC) -o $(TEST) $(SRC) $(TESTS) -lcriterion --coverage
				@echo "======== STRING DEV ========"
				@$(TEST)
				@gcovr --exclude tests/
				@echo "============================"

tests_run:	unit_tests
				@$(TEST)
