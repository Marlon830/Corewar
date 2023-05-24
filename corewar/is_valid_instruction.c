/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** is_valid_instruction.c
*/

#include "corewar.h"

int check_type_arg(vm_t *vm, champion_t *champ, int *j)
{
    char bytecode = vm->arena[champ->pc + 1];
    char type = 0;
    for (int i = 0; i < op_tab[vm->arena[champ->pc] - 1].nbr_args; i++) {
        type = 0;
        set_bit_at(&type, 1, (get_bit_at(bytecode, *j)));
        set_bit_at(&type, 0, (get_bit_at(bytecode, *j - 1)));
        *j -= 2;
        if (type == 1 && get_bit_at(op_tab[vm->arena[champ->pc] - 1].type[i],
        0) == 0)
            return 0;
        if (type == 2 && get_bit_at(op_tab[vm->arena[champ->pc] - 1].type[i],
        1) == 0)
            return 0;
        if (type == 3 && get_bit_at(op_tab[vm->arena[champ->pc] - 1].type[i],
        2) == 0)
            return 0;
        if (type == 0)
            return 0;
    }
    return 1;
}

int check_coding_byte(vm_t *vm, champion_t *champ)
{
    char type = 0;
    int j = 7;
    char bytecode = vm->arena[champ->pc + 1];

    if (!check_type_arg(vm, champ, &j))
        return 0;
    for (int i = op_tab[vm->arena[champ->pc] - 1].nbr_args; i < 4; i++) {
        type = 0;
        set_bit_at(&type, 1, (get_bit_at(bytecode, j)));
        set_bit_at(&type, 0, (get_bit_at(bytecode, j - 1)));
        j -= 2;
        if (type != 0)
            return 0;
    }
    return 1;
}

int is_valid_instruction(vm_t *vm, champion_t *champ)
{
    if (vm->arena[champ->pc] != 1 && vm->arena[champ->pc] != 9 &&
    vm->arena[champ->pc] != 12 && vm->arena[champ->pc] != 15) {
        if (!check_coding_byte(vm, champ))
            return 0;
    }
    return 1;
}
