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
}

void add_elem_to_list(list_t *list, char *label)
{
    list_t *temp = list;
    list_t *new = malloc(sizeof(*new));

    if (list->label == NULL) {
        list->label = label;
        free(new);
        return;
    }
    new->label = label;
    new->next = NULL;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}
