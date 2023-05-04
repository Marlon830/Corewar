/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** corewar.h
*/

#pragma once

#include "corewar.h"

int check_args(char **argv, int id, vm_t *vm);
int check_valid_champ(char **argv, int id, vm_t *vm);
int check_next_prog_num(char **argv, int id, vm_t *vm);
int check_next_address(char **argv, int id, vm_t *vm);
bool check_champions_exist(char *champ_path, vm_t *vm);
champion_t *new_champ(char *champ_path, vm_t *vm);
