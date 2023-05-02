/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** strings.c
*/

#include "asm.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int skip_space(char *str)
{
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return i;
}

char *get_word(char *str)
{
    char *ans = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = skip_space(str);
    int j = 0;

    for (; str[i] != ' ' &&
    str[i] != '\0' &&
    str[i] != '\t' &&
    str[i] != '\n'; i++)
        ans[j++] = str[i];
    ans[j] = '\0';
    return ans;
}

int count_word(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '\n' || str[i] == '\0' || str[i] == '#')
            break;
        count++;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    return count;
}

char **str_to_arr(char *str)
{
    char **arr = malloc_2d_array(count_word(str), my_strlen(str));
    int pos_char = 0;
    int pos_word = 0;

    while (str[pos_char] != '\0' && str[pos_char] != '\n' &&
    str[pos_char] != '#') {
        arr[pos_word++] = get_word(str + pos_char);
        pos_char += skip_space(str + pos_char);
        pos_char += my_strlen(arr[pos_word - 1]);
        pos_char += skip_space(str + pos_char);
    }
    return arr;
}
