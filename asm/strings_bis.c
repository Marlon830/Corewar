/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** strings_bis.c
*/

#include "asm.h"

char **malloc_2d_array(int row, int col)
{
    char **ans = malloc(sizeof(char *) * (row + 1));
    int i = 0;

    for (; i != row; i++)
        ans[i] = malloc(sizeof(char) * (col + 1));
    ans[i] = NULL;
    return ans;
}
