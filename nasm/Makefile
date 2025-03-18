##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY:	all clean fclean re truth test

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SRC		=	memcpy.asm			\
			memmove.asm			\
			memset.asm			\
			strcasecmp.asm		\
			strchr.asm			\
			strcmp.asm			\
			strcspn.asm			\
			strlen.asm			\
			strncmp.asm			\
			strpbrk.asm			\
			strrchr.asm			\
			strstr.asm			\

OBJ		=	$(SRC:.asm=.o)

OUT		=	libasm.so

all:		$(OUT)

$(OUT):		$(OBJ)
				ld -shared $(OBJ) -o $(OUT)

%.o: 		%.asm
				nasm -f elf64 $<

clean:
				rm -f $(OBJ)

fclean:		clean
				rm -f $(OUT) test

re:			fclean $(OUT)

truth:		re
				gcc main.c -o test
				@./test
				@make fclean > /dev/null 2>&1

test:		re
				gcc main.c -o test
				@LD_PRELOAD=$(CWD)/$(OUT):$$LD_PRELOAD ./test
				@make fclean > /dev/null 2>&1
