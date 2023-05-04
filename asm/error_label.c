/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_label.c
*/

#include "asm.h"

int check_name_label_defined(char *label)
{
    int len = my_strlen(label);

    if ((label[0] >= '0' && label[0] <= '9') ||
    ((label[0] < 'a' || label[0] > 'z') && label[0] != '_'))
        return 0;
    for (int i = 1; i < len - 1; i++) {
        if (!is_alphanum(label[i]) && label[i] != '_')
            return 0;
    }
    return 1;
}

int check_name_label_used(char *label)
{
    int len = my_strlen(label);

    for (int i = 2; i < len - 1; i++) {
        if (!is_alphanum(label[i]) && label[i] != '_')
            return 0;
    }
    if (!is_alphanum(label[len - 1]) && label[len - 1] != '_' &&
    label[len - 1] != ',')
        return 0;
    return 1;
}

int is_name_labels_correct(list_t *list)
{
    list_t *temp = list;

    if (temp->label == NULL)
        return 1;
    while (temp != NULL) {
        if (temp->label[0] == '%' && !check_name_label_used(temp->label))
            return 0;
        if (temp->label[0] != '%' && !check_name_label_defined(temp->label))
            return 0;
        temp = temp->next;
    }
    return 1;
}

void get_labels(char **arr, error_t *error)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (i == 0 && arr[i][my_strlen(arr[i]) - 1] == ':')
            add_elem_to_list(error->labels_defined, arr[i]);
        if (i != 0 && arr[i][0] == '%' && arr[i][1] == ':')
            add_elem_to_list(error->labels_used, arr[i]);
    }
}
