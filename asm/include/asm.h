/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** asm.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"

typedef struct error_s {
    int have_name;
    int have_comment;
} error_t;

char **str_to_arr(char *str);
int my_strlen(char *str);
int check_error(char *argv[]);
char **malloc_2d_array(int row, int col);
int my_strcmp(char *s1, char *s2);
int how_many_char_in_str(char c, char *str);
void check_name_and_comment(error_t *error, char **arr);
void compile_champion(char *argv[]);
