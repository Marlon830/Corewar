/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** verif_param
*/

#include "asm.h"

int is_index_bis(char **arr, int pos, char *instruction)
{
    if (!my_strcmp(instruction, "sti")) {
        if (!my_strcmp(instruction, arr[0]) &&
        ((pos == 2 && !is_reg(arr[2])) || (pos == 3 && !is_reg(arr[3]))))
            return 1;
        if (!my_strcmp(instruction, arr[1]) &&
        ((pos == 3 && !is_reg(arr[3])) || (pos == 4 && !is_reg(arr[4]))))
            return 1;
    }
    if (!my_strcmp(instruction, "fork"))
        return 1;
    if (!my_strcmp(instruction, "lldi")) {
        if (!my_strcmp(instruction, arr[0]) &&
        (pos == 1 || pos == 2))
            return 1;
        if (!my_strcmp(instruction, arr[1]) &&
        (pos == 2 || pos == 3))
            return 1;
    }
    return 0;
}

int is_index(char **arr, int pos)
{
    char *instruction = get_instruction(arr);

    if (!my_strcmp(instruction, "zjmp"))
        return 1;
    if (!my_strcmp(instruction, "ldi")) {
        if (!my_strcmp(instruction, arr[0]) &&
        (pos == 1 || pos == 2))
            return 1;
        if (!my_strcmp(instruction, arr[1]) &&
        (pos == 2 || pos == 3))
            return 1;
    }
    if (!my_strcmp(instruction, "lfork"))
        return 1;
    return is_index_bis(arr, pos, instruction);
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
