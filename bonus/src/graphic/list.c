/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** list.c
*/

#include "corewar.h"

void push(list_t **list, void *elt)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *list;

    node->elt = elt;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}
