/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_gestion.c
*/

#include "asm.h"

error_t *init_struct(void)
{
    error_t *error = malloc(sizeof(*error));

    error->labels_defined = init_list();
    error->labels_used = init_list();
    error->have_name = 0;
    error->have_comment = 0;
    return error;
}

int check_error_label(error_t *error)
{
    if (!is_name_labels_correct(error->labels_defined) ||
    !is_name_labels_correct(error->labels_used) ||
    is_same_label(error->labels_defined) ||
    !check_label_exist(error->labels_defined, error->labels_used))
        return 1;
    return 0;
}

int check_error_bis(error_t *error)
{
    if (check_error_label(error))
        return 84;
    if (error->have_name != 1 || error->have_comment != 1)
        return 84;
    return 0;
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
        if (arr[0] == NULL)
            continue;
        check_name_and_comment(error, arr);
        if (verif_functions_param(arr) == 0)
            return 84;
    }
    return check_error_bis(error);
}
