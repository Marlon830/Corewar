/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** assets_label.c
*/

#include "asm.h"


label_t *init_label_list(void)
{
    label_t *label_list = malloc(sizeof(*label_list));

    label_list->name = NULL;
    label_list->next = NULL;
    label_list->pos = 0;
    return label_list;
}

compil_t *init_compil_struct(void)
{
    compil_t *compil = malloc(sizeof(*compil));

    compil->label_list = init_label_list();
    compil->act_pos = 0;
    compil->nb_bytes = 0;
    compil->bytes_line_pos = 0;
    return compil;
}

void add_elem_label_list(label_t *label_list, char *name, int pos)
{
    label_t *temp = label_list;
    label_t *new = malloc(sizeof(*new));

    if (label_list->name == NULL) {
        label_list->name = name;
        label_list->pos = pos;
        free(new);
        return;
    }
    new->name = name;
    new->pos = pos;
    new->next = NULL;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void print_label_list(label_t *label_list)
{
    label_t *temp = label_list;

    if (temp->name == NULL)
        return;
    while (temp != NULL) {
        write(1, "name : ", 7);
        write(1, temp->name, my_strlen(temp->name));
        write(1, "\npos : ", 7);
        my_put_nbr(temp->pos);
        write(1, "\n\n", 2);
        temp = temp->next;
    }
}

label_t *get_label_with_name(label_t *label_list, char *name)
{
    label_t *temp = label_list;
    char *temp_name = malloc(sizeof(char) * my_strlen(name) + 1);

    my_strcpy(temp_name, name);
    if (name[my_strlen(name) - 1] == ',')
        temp_name[my_strlen(name) - 1] = '\0';
    if (temp->name == NULL) {
        free(temp_name);
        return NULL;
    }
    while (temp != NULL) {
        if (!my_strcmp(temp->name, temp_name)) {
            free(temp_name);
            return temp;
        }
        temp = temp->next;
    }
    free(temp_name);
    return NULL;
}
