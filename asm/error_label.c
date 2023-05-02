/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_label.c
*/

#include "asm.h"

void get_labels(char **arr, error_t *error)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (i == 0 && arr[i][my_strlen(arr[i]) - 1] == ':')
            add_elem_to_list(error->labels_defined, arr[i]);
        if (i != 0 && arr[i][0] == '%' && arr[i][1] == ':')
            add_elem_to_list(error->labels_used, arr[i]);
    }
}
