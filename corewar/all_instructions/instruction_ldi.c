/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_ldi.c
*/

#include "corewar.h"

int get_value_indirect(vm_t *vm, champion_t *champion, int copy)
{
    int param = 0;
    int k = 1;

    for (int i = 0; i != 2; i++) {
        for (int j = 0; j != 8; j++)
            set_bit_int_at(&param, j + 8 * k,
            get_bit_at(vm->arena[champion->pc + copy % IDX_MOD + i], j));
        k--;
    }
    return param;
}

int get_ldi_param1(vm_t *vm, champion_t *champion, int *act_pc, int *param1)
{
    int type = 0;
    int copy = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 7));
    *param1 = analyze_type(type, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    copy = *param1;
    if (type == 3)
        *param1 = get_value_indirect(vm, champion, copy);
    return 0;
}

int get_ldi_param2(vm_t *vm, champion_t *champion, int *act_pc, int *param2)
{
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)], 5));
    *param2 = analyze_type(type, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    return 0;
}

void exec_ldi(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    int param1 = 0;
    int param2 = 0;
    int act_pc = my_modulo(champion->pc + 2, MEM_SIZE);

    if (!is_valid_instruction(vm, champion))
        return;
    if (get_ldi_param1(vm, champion, &act_pc, &param1))
        return;
    if (get_ldi_param2(vm, champion, &act_pc, &param2))
        return;
    if (!is_valid_register((int) vm->arena[act_pc], champion))
        return;
    champion->r[(int) vm->arena[act_pc]] =
    vm->arena[my_modulo((champion->pc + (param1 + param2) % IDX_MOD), MEM_SIZE)];
    champion->carry = (champion->r[(int) vm->arena[act_pc]] == 0) ? 1 : 0;
    champion->pc += byte_size;
}
