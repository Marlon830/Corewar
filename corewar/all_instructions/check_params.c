/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_params.c
*/

#include "corewar.h"

int is_index_bis(char instruction, int pos)
{
    if (instruction == sti) {
        if (pos == 1 || pos == 2 )
            return 1;
    }
    if (instruction == fork)
        return 1;
    if (instruction == lldi) {
        if (pos == 1 || pos == 2)
            return 1;
    }
    return 0;
}

int is_index(char instruction, int pos)
{
    if (instruction == zjmp)
        return 1;
    if (instruction == ldi) {
        if (pos == 1 || pos == 2)
            return 1;
    }
    if (instruction == lfork)
        return 1;
    return is_index_bis(instruction, pos);
}
