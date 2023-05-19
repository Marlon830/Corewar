/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_arena
*/

#include "init.h"

void init_register(vm_t *vm)
{
    vm->r = malloc(sizeof(char) * 16);
    for (int i = 0; i != 16; i++)
        vm->r[i] = 0;
}

int init_arena(vm_t *vm)
{
    list_t *temp = vm->champ_list;
    champion_t *champ = NULL;

    vm->cycles = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    init_register(vm);
    vm->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        vm->arena[i] = 0;
    for (; temp != NULL; temp = temp->next) {
        champ = (champion_t *)temp->data;
        if (my_strcory(vm->arena, champ) == 84)
            return 84;
    }
    return 0;
}
