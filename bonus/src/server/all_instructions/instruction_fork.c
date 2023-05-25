/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_fork.c
*/

#include "corewar.h"

void exec_fork(vm_t *vm, champion_t *champion)
{
    int byte_size = 3;
    champion_t *new_champ = copy_champion(champion);
    int act_pc = my_modulo(champion->pc + 1, MEM_SIZE);
    int param = analyze_type(3, &act_pc, champion, vm);

    new_champ->pc = my_modulo(champion->pc + param % IDX_MOD, MEM_SIZE);
    push(&vm->champ_list, new_champ);
    champion->pc += byte_size;
}
