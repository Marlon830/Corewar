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

int get_bit_at(int x, int n)
{
    return ((x >> n) & 1);
}

void set_bit_at(char *x, int n, int value)
{
    *x = *x | value << n;
}

void set_bit_int_at(int *x, int n, int value)
{
    *x = *x | value << n;
}

int power(int nb, int p)
{
    int res = 1;

    for (int i = 0; i < p; i++)
        res *= nb;
    return res;
}
