/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** write_error.c
*/

#include "asm.h"

int write_error(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
