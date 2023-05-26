/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_sti.c
*/

#include "corewar.h"

int get_sti_param2(vm_t *vm, champion_t *champion, int *act_pc, int *param2)
{
    int type = 0;
    int copy = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 5));
    *param2 = analyze_type(type == 1 ? type : 3, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    copy = *param2;
    if (type == 3) {
        *param2 = get_value_indirect(vm, champion, copy);
    }
    return 0;
}

int get_sti_param3(vm_t *vm, champion_t *champion, int *act_pc, int *param3)
{
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 5));
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 2));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[my_modulo(champion->pc + 1,
    MEM_SIZE)], 3));
    *param3 = analyze_type(type == 1 ? type : 3, act_pc, champion, vm);
    if (champion->is_invalid_register) {
        champion->is_invalid_register = false;
        return 1;
    }
    return 0;
}

void exec_sti(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    int param2 = 0;
    int param3 = 0;
    int act_pc = my_modulo(champion->pc + 3, MEM_SIZE);

    if (!is_valid_instruction(vm, champion))
        return;
    if (!is_valid_register((int) vm->arena[my_modulo(champion->pc + 2,
    MEM_SIZE)], champion))
        return;
    if (get_sti_param2(vm, champion, &act_pc, &param2))
        return;
    if (get_sti_param3(vm, champion, &act_pc, &param3))
        return;
    write_four_bytes(vm, my_modulo((champion->pc + (param2 + param3) %
    IDX_MOD), MEM_SIZE),
    champion->r[(int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)]], champion);
    champion->pc += byte_size;
}
