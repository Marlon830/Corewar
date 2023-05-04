/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_arena
*/

#include "init.h"

int init_arena(vm_t *vm)
{
    list_t *temp = vm->champ_list;
    champion_t *champ = NULL;

    vm->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        vm->arena[i] = 0;
    for (; temp != NULL; temp = temp->next) {
        champ = (champion_t *)temp->data;
        if (my_strcory(vm->arena, champ->body, champ->load_address) == 84)
            return 84;
    }
    return 0;
}
