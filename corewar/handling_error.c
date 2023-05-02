/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** handling_error.c
*/

#include "corewar.h"

int handling_error(int argc, char **argv, vm_t *vm)
{
    int check_flag = 0;
    list_t *tmp;

    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        display_help();
    for (int i = 1; i != argc; i++) {
        check_flag = check_args(argv, i, vm);
        if (check_flag == 84)
            return 84;
        i += check_flag;
    }
    if (vm->nbr_cycle <= 0 || vm->nb_champ < 2)
        return 84;
    tmp = vm->champ_list;
    for (int i = 0; i != vm->nb_champ; i++) {
        ((champion_t *)tmp->data)->prog_number = vm->prog_number + i + 1;
        ((champion_t *)tmp->data)->load_address = vm->load_address * i;
        tmp = tmp->next;
    }
    return 0;
}
