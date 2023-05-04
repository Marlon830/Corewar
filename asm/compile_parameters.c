/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_parameters.c
*/

#include "asm.h"

void write_reg(int output_fd, char *param, compil_t *compil)
{
    char reg = 0;

    reg = my_getnbr(param);
    write(output_fd, &reg, 1);
    compil->act_pos += 1;
    compil->bytes_line_pos += 1;
}

void write_ind(int output_fd, char *param, compil_t *compil)
{
    char byte1 = 0;
    char byte2 = 0;
    int nb = my_getnbr(param);

    for (int i = 0; i < 8; i++) {
        set_bit_at(&byte1, i, nb >> i & 1);
        set_bit_at(&byte2, i, nb >> (i + 8) & 1);
    }
    write(output_fd, &byte2, 1);
    write(output_fd, &byte1, 1);
    compil->act_pos += 2;
    compil->bytes_line_pos += 2;
}

void write_dir(int output_fd, char *param, compil_t *compil)
{
    char byte1 = 0;
    char byte2 = 0;
    char byte3 = 0;
    char byte4 = 0;
    int nb = my_getnbr(param);

    for (int i = 0; i < 8; i++) {
        set_bit_at(&byte1, i, nb >> i & 1);
        set_bit_at(&byte2, i, nb >> (i + 8) & 1);
        set_bit_at(&byte3, i, nb >> (i + 16) & 1);
        set_bit_at(&byte4, i, nb >> (i + 24) & 1);
    }
    write(output_fd, &byte4, 1);
    write(output_fd, &byte3, 1);
    write(output_fd, &byte2, 1);
    write(output_fd, &byte1, 1);
    compil->act_pos += 4;
    compil->bytes_line_pos += 4;
}

void write_index(int output_fd, char *param, compil_t *compil)
{
    label_t *label;
    char byte1 = 0;
    char byte2 = 0;
    int nb = 0;

    if (param[1] != ':') {
        write_ind(output_fd, param, compil);
        return;
    }
    label = get_label_with_name(compil->label_list, param + 2);
    nb = (label->pos + compil->bytes_line_pos - 1) - compil->act_pos;
    for (int i = 0; i < 8; i++) {
        set_bit_at(&byte1, i, nb >> i & 1);
        set_bit_at(&byte2, i, nb >> (i + 8) & 1);
    }
    write(output_fd, &byte2, 1);
    write(output_fd, &byte1, 1);
    compil->act_pos += 2;
    compil->bytes_line_pos += 2;
}

void write_parameters(int output_fd, char **arr, compil_t *compil)
{
    int pos = 0;

    if (!my_strcmp(arr[0], get_instruction(arr)))
        pos += 1;
    else
        pos += 2;
    for (; arr[pos] != NULL; pos++) {
        if (is_index(arr, pos)) {
            write_index(output_fd, arr[pos], compil);
            continue;
        }
        if (is_reg(arr[pos]))
            write_reg(output_fd, arr[pos], compil);
        if (is_dir(arr[pos]))
            write_dir(output_fd, arr[pos], compil);
        if (is_ind(arr[pos]))
            write_ind(output_fd, arr[pos], compil);
    }
}
