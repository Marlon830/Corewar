/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** write_instructions.c
*/

#include "asm.h"

char get_coding_byte(char **arr, op_t op)
{
    char ans = 0;
    char all_args[4] = {0, 0, 0, 0};
    int j = 3;

    for (int i = 0; i != op.nbr_args; i++) {
        if (is_reg(arr[i]))
            all_args[i] = 1;
        if (is_dir(arr[i]))
            all_args[i] = 2;
        if (is_ind(arr[i]))
            all_args[i] = 3;
    }
    for (int i = 0; i != 8; i += 2) {
        set_bit_at(&ans, i, all_args[j] >> 0 & 1);
        set_bit_at(&ans, i + 1, all_args[j--] >> 1 & 1);
    }
    return ans;
}

char *get_instruction(char **arr)
{
    if (arr[0][0] == '.')
        return "\0";
    if (arr[0][my_strlen(arr[0]) - 1] == ':')
        return arr[1];
    return arr[0];
}

char *check_instruction_cb(char **arr)
{
    if (!my_strcmp("live", arr[0]) || !my_strcmp("zjmp", arr[0]) ||
    !my_strcmp("fork", arr[0]) || !my_strcmp("lfork", arr[0]))
        return "\0";
    if (arr[0][0] == '.')
        return "\0";
    if (arr[0][my_strlen(arr[0]) - 1] == ':')
        return arr[1];
    return arr[0];
}

void write_instructions(int output_fd, char **arr)
{
    char coding_byte = 0;

    for (int i = 0; op_tab[i].nbr_args != 0; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, get_instruction(arr)))
            write(output_fd, &op_tab[i].code, 1);
        if (!my_strcmp(op_tab[i].mnemonique, check_instruction_cb(arr))) {
            coding_byte = get_coding_byte(arr + 1, op_tab[i]);
            write(output_fd, &coding_byte, 1);
        }
        if (!my_strcmp(op_tab[i].mnemonique, get_instruction(arr)))
            write_parameters(output_fd, arr);
    }
}
