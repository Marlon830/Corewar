/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_name_and_comment.c
*/

#include "asm.h"

int check_validity_name_comment(char **arr, int max_len)
{
    int ans = 0;
    int nb_quotes = 0;
    if (arr[1] == NULL)
        return 0;
    if (arr[1][0] != '"')
        return 0;
    for (int i = 1; arr[i] != NULL; i++) {
        if (arr[i][my_strlen(arr[i]) - 1] == '"' && arr[i + 1] != NULL)
            return 0;
        if (arr[i + 1] == NULL && arr[i][my_strlen(arr[i]) - 1] != '"')
            return 0;
        nb_quotes += how_many_char_in_str('"', arr[i]);
        ans += my_strlen(arr[i]);
    }
    if (nb_quotes != 2)
        return 0;
    ans -= 2;
    if (ans > max_len)
        return 0;
    return 1;
}

void check_name_and_comment(error_t *error, char **arr)
{
    if (arr[0] == NULL)
        return;
    if (!my_strcmp(".name", arr[0])) {
        if (error->have_name == 1)
            error->have_name = 84;
        if (check_validity_name_comment(arr, 128))
            error->have_name += 1;
    }
    if (!my_strcmp(".comment", arr[0])) {
        if (error->have_comment == 1)
            error->have_comment = 84;
        if (check_validity_name_comment(arr, 2048))
            error->have_comment += 1;
    }
}
