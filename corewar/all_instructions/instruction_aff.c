/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** instruction_aff.c
*/

#include "corewar.h"

void exec_aff(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[my_modulo(champion->pc + 1, MEM_SIZE)]);
    char value = 0;

    if (!is_valid_instruction(vm, champion))
        return;
    if (!is_valid_register((int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)], champion))
        return;
    value = champion->r[(int) vm->arena[my_modulo(champion->pc + 2, MEM_SIZE)]] % 256;
    write(1, &value, 1);
    champion->pc += byte_size;
}
