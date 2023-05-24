/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** assets_live.c
*/

#include "corewar.h"

list_t *get_champion_with_prog_number(list_t *champ_list, int prog_number)
{
    champion_t *champ_data;
    list_t *ret_champ_list = NULL;

    while (champ_list != NULL) {
        champ_data = champ_list->data;
        if (champ_data->prog_number == prog_number)
            push(&ret_champ_list, champ_data);
        champ_list = champ_list->next;
    }
    return ret_champ_list;
}

int get_live_params(vm_t *vm, champion_t *champion)
{
    char temp_byte = 0;
    int param = 0;
    int k = 0;

    for (int i = champion->pc + 4; i >= champion->pc + 1; i--) {
        temp_byte = vm->arena[i];
        for (int j = 0; j < 8; j++)
            set_bit_int_at(&param, k * 8 + j, get_bit_at(temp_byte, j));
        k++;
    }
    return param;
}
