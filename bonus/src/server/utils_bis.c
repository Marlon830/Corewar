/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** utils_bis.c
*/

#include "corewar.h"

int my_modulo(int nb, int modulo)
{
    int ret_nb = nb % modulo;

    if (ret_nb < 0)
        ret_nb += modulo;
    return ret_nb;
}

int get_nb_champ(champion_t *champ, list_t *champ_list)
{
    list_t *temp = champ_list;
    champion_t *temp_champ;
    int count = 1;

    while (temp != NULL) {
        temp_champ = temp->data;
        if (temp_champ->prog_number == champ->prog_number)
            return count;
        count++;
        temp = temp->next;
    }
    return -1;
}
