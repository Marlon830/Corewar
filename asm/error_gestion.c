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
    error->line = -1;
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
        return write_error(BOLD"no name or comment\n"NC, -1, NULL);
    return 0;
}

void my_strcpy_without_comment(char *dest, char *src)
{
    int i = 0;

    for (; src[i] != '\0' && src[i] != '#'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

int check_error(char *argv[])
{
    FILE *stream = fopen(argv[1], "r");
    char *line = NULL;
    char **arr;
    error_t *error = init_struct();
    char *temp;
    if (stream == NULL)
        return write_error("can't open file\n", -1, NULL);
    while (getline(&line, &(size_t){0}, stream) != -1) {
        temp = malloc(sizeof(char) * my_strlen(line) + 1);
        my_strcpy_without_comment(temp, line);
        arr = str_to_arr(temp);
        error->line += 1;
        if (arr[0] == NULL || arr[0][0] == '\0')
            continue;
        get_labels(arr, error);
        check_name_and_comment(error, arr);
        if (verif_functions_param(arr) == 0)
            return write_error("invalid param ", error->line + 1, argv);
    }
    return check_error_bis(error);
}
