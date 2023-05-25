/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** main.c
*/

#include "corewar.h"

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    vm->nbr_cycle = 0;
    vm->nbr_cycle_to_print = -1;
    vm->load_address = -1;
    vm->prog_number = -1;
    vm->nb_champ = 0;
    vm->champ_list = NULL;
    vm->nbr_live = 0;
    return vm;
}

char *get_arena_at_cycle(int argc, char **argv, int cycle)
{
    vm_t *vm = init_vm();

    if (handling_error(argc, argv, vm))
        return NULL;
    fill_champ_list(vm);
    if (init_arena(vm)) {
        write(2, "Error: init arena\n", 18);
        return NULL;
    }
    main_loop(vm, cycle);
    return vm->arena;
}
