/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** strings_four.c
*/

#include "asm.h"

int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9') || c == '-')
        return 1;
    return 0;
}
