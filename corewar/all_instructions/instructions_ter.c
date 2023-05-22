/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions_ter
*/

#include "corewar.h"

void exec_zjmp(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;
    int param = get_value_of_param(vm, 3, champion->pc + 1);

    if (!champion->carry) {
        champion->pc += byte_size;
        return;
    }
    champion->pc = champion->pc + param % IDX_MOD;
}

int get_value_indirect(vm_t *vm, champion_t *champion, int copy)
{
    int param = 0;

    for (int i = 0; i != 2; i++) {
        for (int j = 0; j != 8; j++)
            set_bit_int_at(&param, j + 8 * i,
            get_bit_at(vm->arena[champion->pc + copy % IDX_MOD + i], j));
    }
    return param;
}

void exec_ldi(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int param2 = 0;
    int type = 0;
    int act_pc = champion->pc + 2;
    int copy = 0;
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = analyze_type(type, &act_pc, champion, vm);
    copy = param1;
    if (type == 3)
        param1 = get_value_indirect(vm, champion, copy);
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    param2 = analyze_type(type, &act_pc, champion, vm);
    champion->r[(int) vm->arena[act_pc]] =
    vm->arena[champion->pc + (param1 + param2) % IDX_MOD];
    champion->carry = (champion->r[(int) vm->arena[act_pc]] == 0) ? 1 : 0;
    champion->pc += byte_size;
}

void exec_sti(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int type = 0;
    int param2 = 0;
    int param3 = 0;
    int act_pc = champion->pc + 3;
    int copy = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    param2 = analyze_type(type == 1 ? type : 3, &act_pc, champion, vm);
    copy = param2;
    if (type == 3)
        param2 = get_value_indirect(vm, champion, copy);
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 2));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 3));
    param3 = analyze_type(type == 1 ? type : 3, &act_pc, champion, vm);
    write_four_bytes(vm->arena, champion->pc + (param2 + param3) % IDX_MOD,
    champion->r[(int) vm->arena[champion->pc + 2]]);
    champion->pc += byte_size;
}

void exec_fork(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;
    champion_t new_champ = *champion;
    int act_pc = champion->pc + 1;
    int param = analyze_type(3, &act_pc, champion, vm);

    new_champ.pc = champion->pc + param % IDX_MOD;
    push(&vm->champ_list, &new_champ);
    champion->pc += byte_size;
}
