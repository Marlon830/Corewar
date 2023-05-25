/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** utils_bis.c
*/

#include "corewar.h"

int my_modulo(int nb, int modulo)
{
    int ret_nb = nb % modulo;

    if (ret_nb < 0)
        ret_nb += modulo;
    return ret_nb;
}
