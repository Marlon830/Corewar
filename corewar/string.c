/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** string.c
*/

#include "corewar.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i = i + 1;
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }
    }
    return s1[i] - s2[i];
}

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * -1;
        i = i + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i = i + 1;
    }
    return nb * sign;
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
