##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY: all clean fclean re lint dev

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

MAIN	=	main.py

OUT		=	zappy_ai

all:	$(OUT)

$(OUT):
	cp main.py $(OUT)
	chmod 755 $(OUT)

clean:

fclean:	clean
	rm -f $(OUT)

re:	fclean all
