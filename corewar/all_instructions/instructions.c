/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#include "corewar.h"

void exec_live(vm_t *vm, champion_t *champion)
{
    int byte_size = 5;
    int param = get_live_params(vm, champion);
    champion_t *champion_live =
    get_champion_with_prog_number(vm->champ_list, param);

    if (champion_live != NULL) {
        my_putstr("The player ");
        my_put_nbr(param);
        my_putstr(" (");
        my_putstr(champion_live->header->prog_name);
        my_putstr(")is alive.");
        champion_live->nbr_live += 1;
    }
    champion->pc += byte_size;
    return;
}

void exec_ld(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_st(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}

void exec_add(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);

    champion->pc += byte_size;
    return;
}
