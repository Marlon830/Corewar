/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_ld.c
*/

#include "corewar.h"

int exec_ld_bis(int type, vm_t *vm, champion_t *champion, int param1)
{
    if (type == 2) {
        if (!is_valid_register((int) vm->arena[my_modulo
        (champion->pc + 6, MEM_SIZE)], champion))
            return 1;
        champion->r[(int) vm->arena[my_modulo
        (champion->pc + 6, MEM_SIZE)]] = param1;
        champion->carry = (param1 == 0) ? 1 : 0;
    }
    if (type == 3) {
        if (!is_valid_register((int) vm->arena[my_modulo
        (champion->pc + 4, MEM_SIZE)], champion))
            return 1;
        champion->r[(int) vm->arena[my_modulo(champion->pc + 4, MEM_SIZE)]] =
        vm->arena[my_modulo(champion->pc + param1 % IDX_MOD, MEM_SIZE)];
        champion->carry = (champion->r[(int)
        vm->arena[my_modulo(champion->pc + 4, MEM_SIZE)]] == 0) ? 1 : 0;
    }
    return 0;
}

void exec_ld(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    int param1 = 0;
    int type = 0;

    if (!is_valid_instruction(vm, champion))
        return;
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo
    (champion->pc + 1, MEM_SIZE)], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo
    (champion->pc + 1, MEM_SIZE)], 7));
    param1 = get_value_of_param(vm, type,
    my_modulo(champion->pc + 2, MEM_SIZE));
    if (exec_ld_bis(type, vm, champion, param1))
        return;
    champion->pc += byte_size;
}
