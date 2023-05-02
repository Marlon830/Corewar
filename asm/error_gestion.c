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

    error->have_name = 0;
    error->have_comment = 0;
    return error;
}

void print_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        printf("%s ", arr[i]);
    printf("\n");
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
        if (arr[0] == NULL)
            continue;
        check_name_and_comment(error, arr);
        if (verif_functions_param(arr) == 0)
            return 84;
    }
    if (error->have_name != 1 || error->have_comment != 1)
        return 84;
    return 0;
}
