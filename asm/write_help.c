/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** write_help.c
*/

#include "asm.h"

int write_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./asm file_name[.s]\n\n", 22);
    write(1, "DESCRIPTION\n", 12);
    write(1, BOLD"\tfile_name"NC, my_strlen(BOLD"\tfile_name"NC));
    write(1, "\tfile in assembly language to be converted ", 43);
    write(1, "into file_name.cor, an\n\t\t\texecutable in the Virtual ", 52);
    write(1, "Machine.\n", 9);
    return 0;
}
