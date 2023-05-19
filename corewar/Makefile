##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = 	$(shell find -name "*.c")

SRC_TESTS = ../tests/tests_corewar/tests_corewar.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./include

TARGET = corewar

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

tests_run: fclean
	$(CC) -o unit-tests $(SRC_TESTS) \
	$(shell find . -name "*.c" -not -name "main.c") \
	$(CPPFLAGS) $(CFLAGS) --coverage -lcriterion
	./unit-tests
