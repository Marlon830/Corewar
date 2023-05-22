/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_value_of_param.c
*/

#include "corewar.h"

int get_value_of_param_bis(vm_t *vm, int pc, int offset)
{
    char temp_byte;
    int param = 0;
    int k = 0;

    for (int i = pc + offset; i >= pc; i--) {
        temp_byte = vm->arena[i];
        for (int j = 0; j < 8; j++)
            set_bit_int_at(&param, k * 8 + j, get_bit_at(temp_byte, j));
        k++;
    }
    return param;
}

int get_value_of_param(vm_t *vm, int type, int pc)
{
    int param = 0;
    char temp_byte;
    int k = 0;

    if (type == 2)
        return get_value_of_param_bis(vm, pc, 3);
    if (type == 3)
        return get_value_of_param_bis(vm, pc, 1);
    return param;
}
