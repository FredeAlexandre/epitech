##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY:	all compile clean fclean re lint

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

MAIN		=	main.c

SRC   		=	prompt.c									\
				builtin.c									\
				get_command.c								\
				free_command.c								\
				my_addslotenv.c								\
				my_clearenv.c								\
				my_environ.c								\
				my_getenv.c									\
				my_initenv.c								\
				my_lengthenv.c								\
				my_putenv.c									\
				my_rmslotenv.c								\
				my_searchenv.c								\
				my_setenv.c									\
				my_storenv.c								\
				my_unsetenv.c								\
				my_arrlen.c									\
				absolute_path.c								\
				find_executable.c							\
				execute.c									\
				check_pipe.c								\
				next_is_pipe.c								\
				pipe.c									\
				find_pipes.c								\
				execute_function.c							\
				separator.c								\

TESTS		=	tests/test_initenv.c						\
				tests/test_getenv.c							\
				tests/test_putenv.c							\
				tests/test_setenv.c							\
				tests/test_unsetenv.c						\
				tests/test_absolute_path.c					\

OBJ			=	$(SRC:.c=.o)
OBJM		=	$(MAIN:.c=.o)
TMP			=	$(SRC:.c=.c~)
TMPM		=	$(MAIN:.c=.c~)

OUT			=	mysh
OUTT		=	mysh_tests

CFLAGS		=	-fno-builtin -W -Wall
CLIBS		=	-L./libs/string -lmystring -L./libs/utils -lmyutils

all:		compile

lib_compile:
				make -C libs/string/src
				make -C libs/utils/src

compile:	lib_compile
				$(CC) $(SRC) $(MAIN) -c
				$(CC) $(OBJ) $(OBJM) -o $(OUT) $(CLIBS)

clean:
				make -C libs/string/src clean
				make -C libs/utils/src clean
				rm -f $(OBJ) $(OBJM) $(TMP) $(TMPM) *.gcda *.gcno

fclean:		clean
				make -C libs/string/src fclean
				make -C libs/utils/src fclean
				rm -f $(OUT) $(OUTT)

re:			fclean all

.ONESHELL:
lint:		fclean
				@cd "$(CWD)"
				@coding-style . . > /dev/null 2>&1
				@cat coding-style-reports.log
				@rm -f coding-style-reports.log

run_tests:	unit_tests
				$(OUTT)

unit_tests:	fclean lib_compile
				$(CC) $(CFLAGS) $(SRC) $(TESTS) -o $(OUTT) $(CLIBS) \
					-lcriterion

coverage:	fclean lib_compile
				$(CC) $(CFLAGS) $(SRC) $(TESTS) -o $(OUTT) $(CLIBS) \
					-lcriterion --coverage

dev:		re
				make -C libs/string/src fclean
				@make clean > /dev/null 2>&1

test:		coverage
				@valgrind ./$(OUTT)
				@gcovr --exclude tests/
				@make fclean > /dev/null 2>&1
