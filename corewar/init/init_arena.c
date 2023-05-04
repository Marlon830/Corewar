/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_arena
*/

#include "init.h"

void init_arena(vm_t *vm)
{
    list_t *temp = vm->champ_list;
    
    vm->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        vm->arena[i] = 0;
    
}
