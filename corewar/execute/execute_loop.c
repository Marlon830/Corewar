/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execute_loop
*/

#include "corewar.h"

void cycle_gestion(vm_t *vm)
{
    if (nb_of_live(vm) >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_cycle = 0;
    }
    if (vm->nbr_cycle == vm->cycle_to_die) {
        check_alive(vm);
    }
    vm->nbr_cycle++;
    vm->cycles++;
}

int main_loop(vm_t *vm)
{
    while (verif_whos_alive(vm)) {
        cycle_gestion(vm);
    }
    return 0;
}
