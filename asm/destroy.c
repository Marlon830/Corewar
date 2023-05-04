/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** destroy
*/

#include "asm.h"

void free_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i] != NULL)
            free(arr[i]);
    }
    free(arr);
}
