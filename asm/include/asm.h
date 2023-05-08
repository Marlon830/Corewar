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
#define RED "\33[31m"
#define BOLD "\33[1m"
#define NC "\33[0m"
#define PURPLE "\33[35m"

typedef struct list_s {
    char *label;
    int line;
    struct list_s *next;
} list_t;

typedef struct error_s {
    int line;
    int have_name;
    int have_comment;
    list_t *labels_defined;
    list_t *labels_used;
} error_t;

typedef struct label_s {
    char *name;
    int pos;
    struct label_s *next;
} label_t;

typedef struct compil_s {
    label_t *label_list;
    int nb_bytes;
    int act_pos;
    int bytes_line_pos;
} compil_t;

char **str_to_arr(char *str);
int my_strlen(char *str);
int is_alphanum(char c);
int my_getnbr(char *str);
int check_error(char *argv[]);
void get_labels(char **arr, error_t *error);
int is_name_labels_correct(list_t *list, char *argv[]);
int is_same_label(list_t *list, char *argv[]);
int is_index(char **arr, int pos);
char *get_name_defined_label(char *label);
int check_label_exist(list_t *label_defined, list_t *label_used, char *argv[]);
char **malloc_2d_array(int row, int col);

list_t *init_list(void);
void add_elem_to_list(list_t *list, char *label, int line);
void print_list(list_t *list);

int is_alphanumeric(char c);
int my_strcmp(char *s1, char *s2);
void my_strcpy_without_comment(char *dest, char *src);
int how_many_char_in_str(char c, char *str);
void check_name_and_comment(error_t *error, char **arr);
void compile_champion(compil_t *compil, char *argv[]);
void get_all_labels_info(compil_t *compil, char *argv[]);
char *get_instruction(char **arr);
void write_parameters(int output_fd, char **arr, compil_t *compil);
int is_ind(char *str);
int is_dir(char *str);
int is_reg(char *str);
int verif_functions_param(char **arr);
void free_array(char **arr);
void set_bit_at(char *x, int n, int value);
void write_instructions(int output_fd, char **arr, compil_t *compil);
int get_prog_size(char *argv[]);
char *get_header_value(char *argv[], char *value);
void my_strcpy(char *dest, char *src);
void my_put_nbr(int nb);
char *check_instruction_cb(char **arr);
int get_nb_to_write(char *param, compil_t *compil, int is_direct);

compil_t *init_compil_struct(void);
label_t *init_label_list(void);
void add_elem_label_list(label_t *label_list, char *name, int pos);
void print_label_list(label_t *label_list);
label_t *get_label_with_name(label_t *label_list, char *name);

int reverse_endian(int x);
int write_error(char *str, int line, char *argv[]);
int write_help(void);
