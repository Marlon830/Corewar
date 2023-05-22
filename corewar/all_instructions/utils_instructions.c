/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** utils_instructions.c
*/

#include "corewar.h"

void get_nb_byte_bis(char instruction, int *pos, char *count, int temp)
{
    if (is_index(instruction, *pos)) {
        *count += 2;
        *pos += 1;
        return;
    }
    if (temp == 2)
        *count += 4;
    if (temp == 3)
        *count += 2;
    *pos += 1;
}

int get_nb_byte(char instruction, char bytecode)
{
    char count = 0;
    int pos = 0;
    char temp = 0;

    for (int i = 7; i >= 0; i -= 2) {
        temp = 0;
        set_bit_at(&temp, 1, (get_bit_at(bytecode, i)));
        set_bit_at(&temp, 0, (get_bit_at(bytecode, i - 1)));
        if (temp == 0)
            continue;
        if (temp == 1) {
            count++;
            pos++;
            continue;
        }
        get_nb_byte_bis(instruction, &pos, &count, temp);
    }
    return count + 2;
}
