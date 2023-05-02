/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** display.c
*/

#include "corewar.h"

void display_help(void)
{
    write(1, "Help: voilà\n", 13);
}

void display_vm_data(vm_t *vm)
{
    printf("nbr_cycle: %d\n", vm->nbr_cycle);
    printf("load_address: %d\n", vm->load_address);
    printf("prog_number: %d\n", vm->prog_number);
    printf("List of champions:\n");
    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        champion_t *champ = tmp->data;
        printf("champ_path: %s\n", champ->path);
        printf("prog_number: %d\n", champ->prog_number);
        printf("load_address: %d\n", champ->load_address);
    }
}
