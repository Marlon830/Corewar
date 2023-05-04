/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** string_3.c
*/

#include "asm.h"

int check_str(char const *str)
{
    int i = 0;
    int len = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] != '-' && str[i] != '+')
            return 84;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        len++;
        i++;
    }
    if (len > 10)
        return 84;
    return 0;
}

int my_getnbr(char const *str)
{
    int signe = 0;
    int i = 0;
    int nbr = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-')
            signe = signe + 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (nbr == 214748364 && str[i] == '8' && signe % 2 == 1
        && (str[i + 1] < '0' || str[i + 1] > '9'))
            return -2147483648;
        nbr = 10 * nbr + str[i] - 48;
        i++;
        if (nbr < 0 || check_str(str) == 84)
            return 0;
    }
    return signe % 2 == 1 ? nbr * -1 : nbr;
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
