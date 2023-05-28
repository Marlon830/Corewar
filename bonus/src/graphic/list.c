/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** list.c
*/

#include "corewar.h"
#include <stdint.h>

void chartohex(char chr, char hexa[3])
{
    hexa[0] = "0123456789ABCDEF"[chr / 16];
    hexa[2] = "0123456789ABCDEF"[chr % 16];
    hexa[1] = ' ';
}

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
