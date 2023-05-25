/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_sub.c
*/

#include "corewar.h"

void exec_sub(vm_t *vm, champion_t *champion)
{
    int byte_size = 5;
    int a = 0;
    int b = 0;
    if (!is_valid_instruction(vm, champion))
        return;
    if (!is_valid_register((int) vm->arena[my_modulo(champion->pc + 2,
    MEM_SIZE)], champion) ||
    !is_valid_register((int) vm->arena[my_modulo(champion->pc + 3,
    MEM_SIZE)], champion) ||
    !is_valid_register((int) vm->arena[my_modulo(champion->pc + 4,
    MEM_SIZE)], champion))
        return;
    a = champion->r[(int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)]];
    b = champion->r[(int) vm->arena[my_modulo(champion->pc + 3, MEM_SIZE)]];
    champion->r[(int) vm->arena[my_modulo(champion->pc + 4, MEM_SIZE)]] = a - b;
    if (a - b == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}
