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
}

void exec_ld(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = 0;
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 6));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 7));
    param1 = get_value_of_param(vm, type, champion->pc + 2);
    if (type == 2) {
        champion->r[vm->arena[champion->pc + 6]] = param1;
        if (param1 == 0)
            champion->carry = 1;
    }
    if (type == 3) {
        champion->r[vm->arena[champion->pc + 4]] = vm->arena[(champion->pc +
        param1) % IDX_MOD];
        if (champion->r[vm->arena[champion->pc + 4]] == 0)
            champion->carry = 1;
    }
    champion->pc += byte_size;
}

void exec_st(vm_t *vm, champion_t *champion)
{
    int byte_size = get_nb_byte(vm->arena[champion->pc],
    vm->arena[champion->pc + 1]);
    int param1 = champion->r[vm->arena[champion->pc + 2]];
    int param2 = 0;
    int type = 0;

    set_bit_int_at(&type, 0, get_bit_at(vm->arena[champion->pc + 1], 4));
    set_bit_int_at(&type, 1, get_bit_at(vm->arena[champion->pc + 1], 5));
    if (type == 1)
        champion->r[vm->arena[champion->pc + 3]] = param1;
    if (type == 3) {
        param2 = get_value_of_param(vm, type, champion->pc + 3);
        write_four_bytes(vm->arena, (champion->pc + param2) % IDX_MOD, param1);
    }
    champion->pc += byte_size;
}

void exec_add(vm_t *vm, champion_t *champion)
{
    int byte_size = 5;
    int a = champion->r[vm->arena[champion->pc + 2]];
    int b = champion->r[vm->arena[champion->pc + 3]];

    champion->r[vm->arena[champion->pc + 4]] = a + b;
    if (a + b == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += byte_size;
}
