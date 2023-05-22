/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** string_bis.c
*/

#include "corewar.h"

void my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i = i + 1;
        j = j - 1;
    }
}

char *convert_to_hexa(int nb)
{
    char *hexa = malloc(sizeof(char) * 3);
    int i = 0;
    int tmp = 0;

    for (; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10)
            hexa[i] = tmp + 48;
        else
            hexa[i] = tmp + 55;
        nb = nb / 16;
    }
    if (i == 1)
        hexa[i++] = '0';
    hexa[i] = '\0';
    my_revstr(hexa);
    return hexa;
}

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
