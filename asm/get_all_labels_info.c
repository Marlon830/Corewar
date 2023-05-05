/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_all_labels_info.c
*/

#include "asm.h"

void count_bytes_parameters(char **arr, compil_t *compil)
{
    int pos = 0;

    if (!my_strcmp(arr[0], get_instruction(arr)))
        pos += 1;
    else
        pos += 2;
    for (; arr[pos] != NULL; pos++) {
        if (is_index(arr, pos)) {
            compil->nb_bytes += 2;
            continue;
        }
        if (is_reg(arr[pos]))
            compil->nb_bytes += 1;
        if (is_dir(arr[pos]))
            compil->nb_bytes += 4;
        if (is_ind(arr[pos]))
            compil->nb_bytes += 2;
    }
}

void count_bytes(char **arr, compil_t *compil)
{
    for (int i = 0; op_tab[i].nbr_args != 0; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, get_instruction(arr)))
            compil->nb_bytes += 1;
        if (!my_strcmp(op_tab[i].mnemonique, check_instruction_cb(arr))) {
            compil->nb_bytes += 1;
        }
        if (!my_strcmp(op_tab[i].mnemonique, get_instruction(arr))) {
            count_bytes_parameters(arr, compil);
        }
    }
}

void get_all_labels_info(compil_t *compil, char *argv[])
{
    FILE *stream = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    char **arr;
    char *temp;

    while (getline(&line, &len, stream) != -1) {
        temp = malloc(sizeof(char) * my_strlen(line) + 1);
        my_strcpy_without_comment(temp, line);
        arr = str_to_arr(temp);
        if (arr[0] == NULL || arr[0][0] == '\0')
            continue;
        if (IS_LABEL(arr[0]))
            add_elem_label_list(compil->label_list,
            get_name_defined_label(arr[0]), compil->nb_bytes + 1);
        count_bytes(arr, compil);
    }
    fclose(stream);
}
