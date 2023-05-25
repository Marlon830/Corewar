##
## EPITECH PROJECT, 2022
## GraphicCorewar
## File description:
## Makefile
##

SRC = $(shell find . -name "*.c")
CFLAGS = -W -Wextra -Wall
CPPFLAGS = -Iinclude
TARGET = server
OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -g3

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
