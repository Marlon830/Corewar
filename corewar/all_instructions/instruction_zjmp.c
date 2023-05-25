/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_zjmp.c
*/

#include "corewar.h"

void exec_zjmp(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;
    int param = get_value_of_param(vm, 3, my_modulo(champion->pc + 1, MEM_SIZE));

    if (!champion->carry) {
        champion->pc += byte_size;
        return;
    }
    champion->pc = my_modulo(champion->pc + param % IDX_MOD, MEM_SIZE);
}
