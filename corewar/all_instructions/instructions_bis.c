/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions_bis
*/

#include "corewar.h"

void exec_sub(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_and(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_or(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_xor(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}
