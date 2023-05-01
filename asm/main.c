/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** main.c
*/

#include "asm.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 84;
    return check_error(argv);
}
