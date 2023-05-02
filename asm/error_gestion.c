/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_gestion.c
*/

#include "asm.h"

void print_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++);
}

error_t *init_struct(void)
{
    error_t *error = malloc(sizeof(*error));

    error->labels_defined = init_list();
    error->labels_used = init_list();
    error->have_name = 0;
    error->have_comment = 0;
    return error;
}

int check_error(char *argv[])
{
    FILE *stream = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    char **arr;
    error_t *error = init_struct();

    if (stream == NULL)
        return 84;
    while (getline(&line, &len, stream) != -1) {
        arr = str_to_arr(line);
        get_labels(arr, error);
        check_name_and_comment(error, arr);
    }
    if (error->have_name != 1 || error->have_comment != 1)
        return 84;
    return 0;
}
