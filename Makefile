##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = 	asm/main.c \
		corewar/main.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./asm/include -I./corewar/include

all : $(OBJ)
	make -C asm/
	make -C corewar/

clean :
	$(RM) $(OBJ)
	make clean -C asm/
	make clean -C corewar/

fclean : clean
	rm -f asm/asm
	rm -f corewar/corewar

re : fclean all
