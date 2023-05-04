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
#include "string.h"
#include "op.h"

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

typedef struct champion_s {
    int prog_number;
    int load_address;
    char *path;
    header_t *header;
    char *body;
} champion_t;

typedef struct vm_s {
    int nbr_cycle;
    int prog_number;
    int load_address;
    int nb_champ;
    char *arena;
    list_t *champ_list;
} vm_t;

void push(list_t **list, void *data);
void display_help(void);
void display_vm_data(vm_t *vm);
int handling_error(int argc, char **argv, vm_t *vm);
void fill_champ_list(vm_t *vm);
int my_strcory(char *dest, char *src, int n);
int init_arena(vm_t *vm);
