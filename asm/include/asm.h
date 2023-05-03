/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** asm.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"

#define IS_COM(str) (str[0] == '#' || str[0] == '.')
#define IS_LABEL(str) (str[my_strlen(str) - 1] == ':')
#define N_REG(x) (x == 7 || x == 1 || x == 3 || x == 5)
#define N_DIR(x) (x == 2 || x == 6 || x == 3 || x == 7)
#define N_IND(x) (x == 4 || x == 5 || x == 6 || x == 7)

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
int is_alphanum(char c);
int my_getnbr(char const *str);
void set_bit_at(int *x, int n, int value);
char *my_strcpy(char *dest, char *src);
int check_error(char *argv[]);
void get_labels(char **arr, error_t *error);
int is_name_labels_correct(list_t *list);
int is_same_label(list_t *list);
int check_label_exist(list_t *label_defined, list_t *label_used);
char **malloc_2d_array(int row, int col);

list_t *init_list(void);
void add_elem_to_list(list_t *list, char *label);
void print_list(list_t *list);

int my_strcmp(char *s1, char *s2);
int how_many_char_in_str(char c, char *str);
void check_name_and_comment(error_t *error, char **arr);
void compile_champion(char *argv[]);
char *get_instruction(char **arr);
void write_parameters(int output_fd, char **arr, int i);
int is_ind(char *str);
int is_dir(char *str);
int is_reg(char *str);
int verif_functions_param(char **arr);
void free_array(char **arr);
void set_bit_at(char *x, int n, int value);
void write_instructions(int output_fd, char **arr);
int get_prog_size(char *argv[]);
char *get_header_value(char *argv[], char *value);
void my_strcpy(char *dest, char *src);
