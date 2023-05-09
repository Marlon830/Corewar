/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** utils.c
*/

#include "corewar.h"

void push(list_t **list, void *data)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *list;

    node->data = data;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
}
