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

    champion->pc += byte_size;
    return;
}

void exec_lldi(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_lfork(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;

    champion->pc += byte_size;
    return;
}

void exec_aff(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}
