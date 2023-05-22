/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions_bis
*/

#include "corewar.h"

void exec_sub(vm_t *vm, champion_t *champion)
{
    int byte_size = 5;
    int a = champion->r[(int) vm->arena[champion->pc + 2]];
    int b = champion->r[(int) vm->arena[champion->pc + 3]];

    champion->r[(int) vm->arena[champion->pc + 4]] = a - b;
    if (a - b == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}

void exec_and(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int param2 = 0;
    int type = 0;
    int act_pc = champion->pc + 2;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = analyze_type(type, &act_pc, champion, vm);
    type = 0;
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    param2 = analyze_type(type, &act_pc, champion, vm);
    champion->r[(int) vm->arena[act_pc]] = param1 & param2;
    if ((param1 & param2) == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}

void exec_or(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int param2 = 0;
    int type = 0;
    int act_pc = champion->pc + 2;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = analyze_type(type, &act_pc, champion, vm);
    type = 0;
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    param2 = analyze_type(type, &act_pc, champion, vm);
    champion->r[(int) vm->arena[act_pc]] = param1 | param2;
    if ((param1 | param2) == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}

void exec_xor(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int param2 = 0;
    int type = 0;
    int act_pc = champion->pc + 2;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = analyze_type(type, &act_pc, champion, vm);
    type = 0;
    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    param2 = analyze_type(type, &act_pc, champion, vm);
    champion->r[(int) vm->arena[act_pc]] = param1 ^ param2;
    if ((param1 ^ param2) == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}
