##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

all :
	make -C asm/
	make -C corewar/

clean :
	make clean -C asm/
	make clean -C corewar/

fclean : clean
	make fclean -C asm/
	make fclean -C corewar/
	$(RM) tests/*.html tests/*.css

re : fclean all

tests_run:
	make tests_run -C asm/
	make tests_run -C corewar/

bonus_all:
	make -C bonus/client/
