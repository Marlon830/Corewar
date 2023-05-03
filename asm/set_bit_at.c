/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** set_bit_at.c
*/

#include "asm.h"

void set_bit_at(char *x, int n, int value)
{
    *x = *x | value << n;
}
