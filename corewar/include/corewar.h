/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** corewar.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

typedef struct champion_s {
    int prog_number;
    int load_address;
    char *path;
} champion_t;

typedef struct vm_s {
    int nbr_cycle;
    int prog_number;
    int load_address;
    int nb_champ;
    list_t *champ_list;
} vm_t;

int handling_error(int argc, char **argv, vm_t *vm);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);
int my_strlen(char *str);
void push(list_t **list, void *data);
bool check_champions_exist(char *champ_path, vm_t *vm);
champion_t *new_champ(char *champ_path);
void display_help(void);
void display_vm_data(vm_t *vm);
int check_args(char **argv, int id, vm_t *vm);
