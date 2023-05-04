/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** string_3.c
*/

#include "asm.h"

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int my_getnbr(char *str)
{
    int number = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (!is_num(str[i]) && str[i] != '\0')
        i++;
    while (is_num(str[i])) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return sign * number;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
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
