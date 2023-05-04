/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** verif_functions_param
*/

#include "asm.h"
#include "op.h"

int arr_len(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            return i;
    }
    return i;
}

int verif_params(char **arr, int index)
{
    int j = 1;
    int b = 0;
    int a = 0;

    if (arr_len(arr) - 1 != op_tab[index].nbr_args)
        return 0;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        a = op_tab[index].type[i];
        if ((N_REG(a) == 1 && is_reg(arr[j]) == 1))
            b++;
        if ((N_DIR(a) == 1 && is_dir(arr[j]) == 1))
            b++;
        if ((N_IND(a) == 1 && is_ind(arr[j]) == 1))
            b++;
        if (b == 0)
            return 0;
        j++;
        b = 0;
    }
    return 1;
}

int recup_index(char *str)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++) {
        if (my_strcmp(str, op_tab[i].mnemonique) == 0)
            return i;
    }
    return -1;
}

int verif_not_function(char **arr)
{
    if (IS_COM(arr[0]) == 1)
        return 1;
    if (IS_LABEL(arr[0]) == 1)
        return 1;
    return 0;
}

int verif_functions_param(char **arr)
{
    int index;

    if (verif_not_function(arr) == 1)
        return 1;
    index = recup_index(arr[0]);
    if (index == -1)
        return 0;
    return verif_params(arr, index);
}
