/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions_four
*/

#include "corewar.h"

void exec_lld(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = get_value_of_param(vm, type, champion->pc + 2);
    if (type == 2) {
        champion->r[vm->arena[champion->pc + 6]] = param1;
        if (param1 == 0)
            champion->carry = 1;
    }
    if (type == 3) {
        champion->r[vm->arena[champion->pc + 4]] =
        vm->arena[(champion->pc + param1)];
        if (champion->r[vm->arena[champion->pc + 4]] == 0)
            champion->carry = 1;
    }
    champion->pc += byte_size;
}

void exec_lldi(vm_t *vm, champion_t *champion)
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
    champion->r[vm->arena[act_pc]] =
    vm->arena[(champion->pc + param1 + param2)];
    champion->carry = (champion->r[vm->arena[act_pc]] == 0) ? 1 : 0;
    champion->pc += byte_size;
}

void exec_lfork(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;
    champion_t new_champ = *champion;
    int act_pc = champion->pc + 1;
    int param = analyze_type(3, &act_pc, champion, vm);

    new_champ.pc = (champion->pc + param);
    push(&vm->champ_list, &new_champ);
    champion->pc += byte_size;
}

void exec_aff(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    write(1, (char) champion->r[vm->arena[champion->pc + 2]] % 256, 1);
    champion->pc += byte_size;
}
