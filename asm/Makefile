##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = $(shell find -name "*.c")

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./include

TARGET = asm

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
