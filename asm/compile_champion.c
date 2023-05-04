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

void write_header(compil_t *compil, char *argv[], int output_fd)
{
    header_t header = {0};

    header.magic = 0xea83f3;
    header.prog_size = compil->nb_bytes;
    my_strcpy(header.prog_name, get_header_value(argv, ".name"));
    my_strcpy(header.comment, get_header_value(argv, ".comment"));
    write(output_fd, &header, sizeof(header));
}

void compile_champion(compil_t *compil, char *argv[])
{
    FILE *stream = fopen(argv[1], "r");
    int output_fd = open(get_output_file(argv),
    O_RDWR | O_CREAT | O_TRUNC, 0644);
    char *line = NULL;
    size_t len = 0;
    char **arr;

    write_header(compil, argv, output_fd);
    while (getline(&line, &len, stream) != -1) {
        arr = str_to_arr(line);
        if (arr[0] == NULL)
            continue;
        write_instructions(output_fd, arr, compil);
    }
    fclose(stream);
    close(output_fd);
    return;
}
