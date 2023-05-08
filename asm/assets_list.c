/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** assets_list.c
*/

#include "asm.h"

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(*list));

    list->label = NULL;
    list->next = NULL;
    list->line = 1;
    return list;
}

void add_elem_to_list(list_t *list, char *label, int line)
{
    list_t *temp = list;
    list_t *new = malloc(sizeof(*new));

    if (list->label == NULL) {
        list->label = label;
        list->line = line;
        free(new);
        return;
    }
    new->label = label;
    new->next = NULL;
    new->line = line;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void print_list(list_t *list)
{
    list_t *temp = list;

    if (temp->label == NULL)
        return;
    while (temp != NULL) {
        write(1, temp->label, my_strlen(temp->label));
        temp = temp->next;
    }
}
