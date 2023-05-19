/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** life_gestion
*/

#include "corewar.h"

int verif_whos_alive(vm_t *vm)
{
    int nb_alive = 0;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        if (((champion_t *)tmp->data)->alive)
            nb_alive++;
    }
    if (nb_alive <= 1)
        return 0;
    return 1;
}

int nb_of_live(vm_t *vm)
{
    int nb = 0;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        nb += ((champion_t *)tmp->data)->nbr_live;
    }
    return nb;
}

void check_alive(vm_t *vm)
{
    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        if (((champion_t *)tmp->data)->nbr_live == 0)
            ((champion_t *)tmp->data)->alive = false;
        else
            ((champion_t *)tmp->data)->nbr_live = 0;
    }
}
