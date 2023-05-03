/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_parameters.c
*/

#include "asm.h"

void write_reg(int output_fd, char *param)
{
    char reg = 0;

    reg = my_getnbr(param);
    write(output_fd, &reg, 1);
}

void write_ind(int output_fd, char *param)
{
    char byte1 = 0;
    char byte2 = 0;
    int nb = my_getnbr(param);

    set_bit_at(&byte1, 0, (nb >> 0 & 1));
    set_bit_at(&byte1, 1, (nb >> 1 & 1));
    set_bit_at(&byte2, 0, (nb >> 2 & 1));
    set_bit_at(&byte2, 1, (nb >> 3 & 1));
    write(output_fd, &byte2, 1);
    write(output_fd, &byte1, 1);
}

void write_dir(int output_fd, char *param)
{
    char byte1 = 0;
    char byte2 = 0;
    char byte3 = 0;
    char byte4 = 0;
    int nb = my_getnbr(param);

    set_bit_at(&byte1, 0, (nb >> 0 & 1));
    set_bit_at(&byte1, 1, (nb >> 1 & 1));
    set_bit_at(&byte2, 0, (nb >> 2 & 1));
    set_bit_at(&byte2, 1, (nb >> 3 & 1));
    set_bit_at(&byte3, 0, (nb >> 4 & 1));
    set_bit_at(&byte3, 1, (nb >> 5 & 1));
    set_bit_at(&byte4, 0, (nb >> 6 & 1));
    set_bit_at(&byte4, 1, (nb >> 7 & 1));
    write(output_fd, &byte4, 1);
    write(output_fd, &byte3, 1);
    write(output_fd, &byte2, 1);
    write(output_fd, &byte1, 1);
}

void write_parameters(int output_fd, char **arr)
{
    int pos = 0;

    if (!my_strcmp(arr[0], get_instruction(arr)))
        pos += 1;
    else
        pos += 2;
    for (; arr[pos] != NULL; pos++) {
        if (is_reg(arr[pos])) {
            write_reg(output_fd, arr[pos]);
            continue;
        }
        if (is_dir(arr[pos])) {
            write_dir(output_fd, arr[pos]);
            continue;
        }
        if (is_ind(arr[pos])) {
            write_ind(output_fd, arr[pos]);
            continue;
        }
    }
}
