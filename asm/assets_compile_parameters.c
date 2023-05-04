/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** assets_compile_parameters.c
*/

#include "asm.h"

int get_nb_to_write(char *param, compil_t *compil, int is_direct)
{
    int nb = 0;
    label_t *label;
    int offset = 0;

    if (is_direct)
        offset += 1;
    if (param[0 + offset] == ':')
        offset += 1;
    label = get_label_with_name(compil->label_list, param + offset);
    if (label != NULL)
        nb = (label->pos + compil->bytes_line_pos - 1) - compil->act_pos;
    else
        nb = my_getnbr(param);
    return nb;
}
