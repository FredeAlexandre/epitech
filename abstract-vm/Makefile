##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile the project
##

.PHONY: all clean fclean re

CXX			=	g++

SRC			=	src/main.cpp \
				src/Arguments.cpp \
				src/Config.cpp \
				src/Source.cpp \
				src/OperandFactory.cpp \
				src/AOperand.cpp \
				src/OperandInteger.cpp \
				src/OperandDecimal.cpp \
				src/VM.cpp \

OBJ			=	$(SRC:.cpp=.o)

BIN			=	abstractVM

CXXFLAGS	=	-W -Wall -Wextra -Werror

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJ) -o $(BIN)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(BIN)

re: fclean all
