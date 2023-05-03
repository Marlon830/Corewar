/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_champion.c
*/

#include "asm.h"

char *get_output_file(char *argv[])
{
    char *ans = malloc(sizeof(char) * (my_strlen(argv[1]) + 4));
    int i = 0;

    for (; argv[1][i] != '.' || argv[1][i + 1] != 's'; i++)
        ans[i] = argv[1][i];
    ans[i] = '.';
    ans[i + 1] = 'c';
    ans[i + 2] = 'o';
    ans[i + 3] = 'r';
    ans[i + 4] = '\0';
    return ans;
}

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

int get_prog_size(char *argv[])
{
    return 10;
}

char *get_instruction(char **arr)
{
    if (arr[0][0] == '.')
        return "\0";
    if (arr[0][my_strlen(arr[0]) - 1] == ':')
        return arr[1];
    return arr[0];
}

void set_bit_at(int *x, int n, int value)
{
    *x = *x | value << n;
}

char get_coding_byte(char **arr, op_t op)
{
    char ans = 0;
    char all_args[4] = {0, 0, 0, 0};
    int i = 0;
    int j = 0;

    for (int i = 0; i != op.nbr_args; i++) {
        if (is_reg(arr[i]))
            all_args[i] = 1;
        if (is_dir(arr[i]))
            all_args[i] = 2;
        if (is_ind(arr[i]))
            all_args[i] = 3;
    }
    for (int i = 0; i != 8; i += 2) {
        set_bit_at(&ans, i, all_args[j++] >> 0 & 1);
        set_bit_at(&ans, i + 1, all_args[j++] >> 1 & 1);
    }
    for (int i = 7; i >= 0; i--) {
        printf("%i\n", ans >> i & 1);
    }
    return ans;
}

void compile_champion(char *argv[])
{
    FILE *stream = fopen(argv[1], "r");
    int output_fd = open(get_output_file(argv), O_CREAT | O_TRUNC, 0644);
    char *line = NULL;
    size_t len = 0;
    char **arr;
    header_t header = {0xea83f3, get_header_value(argv, ".name"),
    get_prog_size(argv), get_header_value(argv, ".comment")};

    write(output_fd, &header, sizeof(header));
    while (getline(&line, &len, stream) != -1) {
        arr = str_to_arr(line);
        for (int i = 0; op_tab[i].nbr_args != 0; i++) {
            if (!my_strcmp(op_tab[i].mnemonique, get_instruction(arr))) {
                get_coding_byte(arr + 1, op_tab[i]);
                exit(0);
                write(output_fd, op_tab[i].code, 1);
                write(output_fd, &get_coding_byte(arr + 1, op_tab[i]), 1);
            }
        }
    }
    return;
}
