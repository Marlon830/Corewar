/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** asm.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    char *label;
    struct list_s *next;
} list_t;

typedef struct error_s {
    int have_name;
    int have_comment;
    list_t *labels_defined;
    list_t *labels_used;
} error_t;

char **str_to_arr(char *str);
int my_strlen(char *str);
int check_error(char *argv[]);
void get_labels(char **arr, error_t *error);
char **malloc_2d_array(int row, int col);

list_t *init_list(void);
void add_elem_to_list(list_t *list, char *label);
