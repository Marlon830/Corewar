/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** fill_champion.c
*/

#include "init.h"

bool check_prog_number(vm_t *vm, int prog_number)
{
    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        if (((champion_t *)tmp->data)->prog_number == prog_number)
            return false;
    }
    return true;
}

int get_first_prog_number(vm_t *vm)
{
    int prog_number = 1;

    while (true) {
        if (check_prog_number(vm, prog_number))
            break;
        prog_number++;
    }
    return prog_number;
}

void fill_champ_list(vm_t *vm)
{
    champion_t *champ;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        champ = tmp->data;
        if (champ->prog_number == -1)
            champ->prog_number = get_first_prog_number(vm);
        open_bin(champ);
    }
}
