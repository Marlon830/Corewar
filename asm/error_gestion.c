/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_gestion.c
*/

#include "asm.h"

void print_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        printf("%s\n", arr[i]);
}

error_t *init_struct(void)
{
    error_t *error = malloc(sizeof(*error));

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
        print_arr(arr);
    }
    return 0;
}
