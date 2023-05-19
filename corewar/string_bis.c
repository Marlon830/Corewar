/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** string_bis.c
*/

#include "corewar.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar('0' + nb);
        return;
    }
    my_put_nbr(nb / 10);
    my_putchar('0' + (nb % 10));
}
