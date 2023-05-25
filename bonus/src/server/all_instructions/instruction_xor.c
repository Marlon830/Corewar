/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_xor.c
*/

#include "corewar.h"

int get_xor_param1(vm_t *vm, champion_t *champion, int *act_pc, int *param1)
{
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 7));
    *param1 = analyze_type(type, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    return 0;
}

int get_xor_param2(vm_t *vm, champion_t *champion, int *act_pc, int *param2)
{
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 5));
    *param2 = analyze_type(type, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    return 0;
}

void exec_xor(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    int param1 = 0;
    int param2 = 0;
    int act_pc = my_modulo(champion->pc + 2, MEM_SIZE);

    if (!is_valid_instruction(vm, champion))
        return;
    if (get_xor_param1(vm, champion, &act_pc, &param1))
        return;
    if (get_xor_param2(vm, champion, &act_pc, &param2))
        return;
    if (!is_valid_register((int) vm->arena[act_pc], champion))
        return;
    champion->r[(int) vm->arena[act_pc]] = param1 ^ param2;
    if ((param1 ^ param2) == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}
