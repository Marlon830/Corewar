/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** verif_param
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

int is_reg(char *str)
{
    int i = 0;

    if (str[0] != 'r')
        return 0;
    i++;
    for (; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
            return 0;
    }
    return 1;
}

int is_dir(char *str)
{
    int i = 0;

    if (str[0] != '%')
        return 0;
    i++;
    for (; str[i] != '\0'; i++) {
        if (!is_alphanumeric(str[i]) && str[i] != ',' && str[i] != ':')
            return 0;
    }
    return 1;
}

int is_ind(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != '-')
            return 0;
    }
    return 1;
}
