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
    vm->nbr_cycle = -1;
    vm->load_address = -1;
    vm->prog_number = -1;
    vm->nb_champ = 0;
    vm->champ_list = NULL;
    return vm;
}

int main(int argc, char **argv)
{
    vm_t *vm = init_vm();

    if (handling_error(argc, argv, vm))
        return 84;
    fill_champ_list(vm);
    if (init_arena(vm)) {
        write(2, "Error: init arena\n", 18);
        return 84;
    }
    free(vm->arena);
    return 0;
}
