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
	$(RM) unit-tests
	$(RM) *.gcda
	$(RM) *.gcno

fclean : clean
	$(RM) $(TARGET)

re : fclean all

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	$(CC) -o unit-tests ../tests/tests_asm/tests_asm.c \
	$(shell find . -name "*.c" -not -name "main.c") \
	$(CPPFLAGS) $(CFLAGS) --coverage -lcriterion
	./unit-tests
