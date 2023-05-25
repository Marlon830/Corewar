##
## EPITECH PROJECT, 2022
## graphic_corewar
## File description:
## Makefile
##
COREWAR = corewar
SOCKET = socket

all : $(COREWAR) $(SOCKET)

$(COREWAR) :
	$(MAKE) -C src/graphic

$(SOCKET) :
	$(MAKE) -C src/server

clean :
	$(MAKE) clean -C src/graphic
	$(MAKE) clean -C src/server

fclean :
	$(MAKE) fclean -C src/graphic
	$(MAKE) fclean -C src/server

re : fclean all
