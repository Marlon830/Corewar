/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_header.c
*/

#include "asm.h"

char *get_header_value(char *argv[], char *value)
{
    FILE *stream = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    char **arr;
    char *ans;
    int i = 0;
    int j = 0;
    while (getline(&line, &len, stream) != -1) {
        arr = str_to_arr(line);
        if (!my_strcmp(arr[0], value))
            break;
    }
    ans = malloc(sizeof(char) * (my_strlen(line)));
    for (; line[i] != '"'; i++);
    i++;
    for (; line[i] != '"'; i++)
        ans[j++] = line[i];
    ans[j] = '\0';
    return ans;
}
