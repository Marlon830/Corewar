/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** write_error.c
*/

#include "asm.h"

int write_error(char *str, int line, char *argv[])
{
    write(2, RED BOLD"error: "NC, my_strlen(RED BOLD"error: "NC));
    if (line != -1) {
        write(2, str, my_strlen(str));
        write(2, BOLD PURPLE"line ", my_strlen(BOLD PURPLE"line "));
        my_put_nbr(line);
        write(2, "\n"NC, my_strlen("\n"NC));
        write(2, argv[1], my_strlen(argv[1]));
        write(2, ":", 1);
        my_put_nbr(line);
        write(2, "\n", 1);
        return 84;
    }
    write(2, str, my_strlen(str));
    return 84;
}
