##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makfile
##

.PHONY: all clean fclean re lint dev gui server ai

CWD:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

all: gui server ai

.ONESHELL:
clean:
	cd $(CWD)/server
	make clean
	cd ..

fclean:
	cd $(CWD)/server
	make fclean
	cd ..

	rm -f $(CWD)/zappy_ai
	rm -f $(CWD)/ia/zappy_ai
	rm -f $(CWD)/zappy_gui
	rm -rf $(CWD)/gui/build

re:
	cd $(CWD)/server
	make re
	cd ..

	cd $(CWD)/ia
	make re
	cd ..
	printf "#!/bin/bash\n\n./ia/zappy_ai \"\$$@\"\n" > $(CWD)/zappy_ai
	chmod +x $(CWD)/zappy_ai

	rm -f $(CWD)/zappy_gui
	rm -rf $(CWD)/gui/build

	cd $(CWD)/gui
	./compile
	cd ..


.ONESHELL:
gui:
	cd $(CWD)/gui
	./compile
	cd ..

.ONESHELL:
server:
	cd $(CWD)/server
	make
	cd ..

.ONESHELL:
ai:
	cd $(CWD)/ia
	make
	cd ..
	printf "#!/bin/bash\n\n./ia/zappy_ai \"\$$@\"\n" > $(CWD)/zappy_ai
	chmod +x $(CWD)/zappy_ai

