/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_live
*/

#include "corewar.h"

void print_live(int param, champion_t *champion_live)
{
    my_putstr("Le joueur ");
    my_put_nbr(param);
    my_putstr(" (");
    my_putstr(champion_live->header->prog_name);
    my_putstr(") est en vie.\n");
}

void exec_live(vm_t *vm, champion_t *champion)
{
    int byte_size = 5;
    int param = get_live_params(vm, champion);
    champion_t *champion_live;
    list_t *list_champion_live =
    get_champion_with_prog_number(vm->champ_list, param);
    int count = 1;
    int champ_val = 0;

    while (list_champion_live != NULL) {
        champion_live = list_champion_live->data;
        vm->nbr_live += 1;
        champion_live->nbr_live += 1;
        vm->winner = champion_live;
        list_champion_live = list_champion_live->next;
        count++;
        champ_val = get_nb_champ(champion_live, vm->champ_list);
        vm->lives[champ_val - 1] = vm->cycles;
    }
    champion->pc += byte_size;
}
