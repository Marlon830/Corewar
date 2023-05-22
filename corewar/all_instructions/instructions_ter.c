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

    champion->pc += byte_size;
    return;
}

void exec_ldi(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_sti(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_fork(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;

    champion->pc += byte_size;
    return;
}
