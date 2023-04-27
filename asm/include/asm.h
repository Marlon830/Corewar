/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** asm.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct error_s {
    int have_name;
    int have_comment;
} error_t;

char **str_to_arr(char *str);
int my_strlen(char *str);
int check_error(char *argv[]);
char **malloc_2d_array(int row, int col);
