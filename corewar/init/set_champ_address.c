/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** set_champ_address.c
*/

#include "init.h"

int get_champ_len(vm_t *vm)
{
    int len = 0;

    for (list_t *list = vm->champ_list; list; list = list->next) {
        champion_t *champ = list->data;
        len += champ->header->prog_size;
    }
    return len;
}

int nb_champ(vm_t *vm)
{
    int nb = 0;

    for (list_t *list = vm->champ_list; list; list = list->next)
        nb++;
    return nb;
}

void set_champ_address(vm_t *vm)
{
    int len = get_champ_len(vm);
    int offset = MEM_SIZE / nb_champ(vm);
    int i = 0;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        champion_t *champ = tmp->data;
        if (champ->load_address == -1) {
            champ->load_address = i * offset;
            i++;
        }
    }
}
