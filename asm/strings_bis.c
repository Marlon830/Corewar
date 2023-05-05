/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** strings_bis.c
*/

#include "asm.h"

char **malloc_2d_array(int row, int col)
{
    char **ans = malloc(sizeof(char *) * (row + 1));
    int i = 0;

    for (; i != row; i++)
        ans[i] = malloc(sizeof(char) * (col + 1));
    ans[i] = NULL;
    return ans;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;
    while (s1[i] == s2[i]) {
        i = i + 1;
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }
    }
    return s1[i] - s2[i];
}

int how_many_char_in_str(char c, char *str)
{
    int ans = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            ans++;
    }
    return ans;
}

int is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void my_strcpy(char *dest, char *src)
{
    int src_len = my_strlen(src);
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[src_len] = '\0';
}
