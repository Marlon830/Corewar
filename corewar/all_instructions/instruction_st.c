/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_st.c
*/

#include "corewar.h"

int exec_st_bis(int type, vm_t *vm, champion_t *champion, int param1)
{
    if (type == 1) {
        if (!is_valid_register((int) vm->arena[my_modulo(champion->pc + 3, MEM_SIZE)], champion))
            return 1;
        champion->r[(int) vm->arena[my_modulo(champion->pc + 3, MEM_SIZE)]] = param1;
    }
    return 0;
}

void exec_st(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    int param1 = 0;
    int param2 = 0;
    int type = 0;

    if (!is_valid_instruction(vm, champion))
        return;
    if (!is_valid_register((int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)], champion))
        return;
    param1 = champion->r[(int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)]];
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 5));
    if (exec_st_bis(type, vm, champion, param1))
        return;
    if (type == 3) {
        param2 = get_value_of_param(vm, type, my_modulo(champion->pc + 3, MEM_SIZE));
        write_four_bytes(vm->arena, my_modulo(champion->pc + param2 % IDX_MOD, MEM_SIZE), param1);
    }
    champion->pc += byte_size;
}
