/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** flags.c
*/

#include "corewar.h"

bool is_arg(char *arg)
{
    if (arg != NULL && arg[0] != '-')
        return true;
    return false;
}

int check_dump(char **argv, int id, vm_t *vm)
{
    if (!my_strcmp(argv[id], "-dump") && is_arg(argv[id + 1])) {
        if (vm->nbr_cycle != -1)
            return 84;
        vm->nbr_cycle = my_getnbr(argv[id + 1]);
        return 1;
    }
    return 0;
}

int check_next_address(char **argv, int id, vm_t *vm)
{
    if (!my_strcmp(argv[id], "-a") && is_arg(argv[id + 1])) {
        if (vm->load_address != -1)
            return 84;
        vm->load_address = my_getnbr(argv[id + 1]);
        return 1;
    }
    return 0;
}

int check_next_prog_num(char **argv, int id, vm_t *vm)
{
    if (!my_strcmp(argv[id], "-n") && is_arg(argv[id + 1])) {
        if (vm->prog_number != -1)
            return 84;
        vm->prog_number = my_getnbr(argv[id + 1]);
        return 1;
    }
    return 0;
}

int check_args(char **argv, int id, vm_t *vm)
{
    int flag_return = 0;

    flag_return = check_dump(argv, id, vm);
    if (flag_return != 0)
        return flag_return;
    flag_return = check_next_address(argv, id, vm);
    if (flag_return != 0)
        return flag_return;
    flag_return = check_next_prog_num(argv, id, vm);
    if (flag_return != 0)
        return flag_return;
    if (check_champions_exist(argv[id], vm))
        return 0;
    return 84;
}
