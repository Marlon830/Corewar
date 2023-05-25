##
## EPITECH PROJECT, 2022
## GraphicCorewar
## File description:
## Makefile
##

SRC = $(shell find . -name "*.c")
CFLAGS = -W -Wextra -Wall
CPPFLAGS = -Iinclude
TARGET = corewar
OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -lraylib -lm -lopenal -lsndfile

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
