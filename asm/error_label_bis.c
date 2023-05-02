/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** error_label_bis.c
*/

#include "asm.h"

int is_same_label_in_list(list_t *list, char *label)
{
    list_t *temp = list;
    int count = 0;

    if (temp->label == NULL)
        return 0;
    while (temp != NULL) {
        if (!my_strcmp(label, temp->label))
            count++;
        temp = temp->next;
    }
    if (count > 1)
        return 1;
    return 0;
}

int is_same_label(list_t *list)
{
    list_t *temp = list;

    if (temp->label == NULL)
        return 0;
    while (temp != NULL) {
        if (is_same_label_in_list(list, temp->label))
            return 1;
        temp = temp->next;
    }
    return 0;
}

char *get_name_defined_label(char *label)
{
    char *new_label = malloc(sizeof(char) * my_strlen(label) + 1);

    my_strcpy(new_label, label);
    new_label[my_strlen(new_label) - 1] = '\0';
    return new_label;
}

int label_is_in_list(char *label, list_t *list)
{
    char *temp_label = malloc(sizeof(char) * my_strlen(label) + 1);
    list_t *temp = list;
    char *temp_defined;
    my_strcpy(temp_label, label + 2);
    if (label[my_strlen(label) - 1] == ',')
        temp_label[my_strlen(temp_label) - 1] = '\0';
    if (temp->label == NULL) {
        free(temp_label);
        return 0;
    }
    while (temp != NULL) {
        temp_defined = get_name_defined_label(temp->label);
        if (!my_strcmp(temp_defined, temp_label)) {
            free(temp_defined);
            return 1;
        }
        free(temp_defined);
        temp = temp->next;
    }
    return 0;
}

int check_label_exist(list_t *label_defined, list_t *label_used)
{
    list_t *temp = label_used;

    if (temp->label == NULL)
        return 1;
    while (temp != NULL) {
        if (!label_is_in_list(temp->label, label_defined))
            return 0;
        temp = temp->next;
    }
    return 1;
}
