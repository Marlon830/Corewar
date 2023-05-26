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
#include "my_string.h"
#include "op.h"

#define live 0x01
#define ld 0x02
#define st 0x03
#define add 0x04
#define sub 0x05
#define and 0x06
#define or 0x07
#define xor 0x08
#define zjmp 0x09
#define ldi 0x0a
#define sti 0x0b
#define fork 0x0c
#define lld 0x0d
#define lldi 0x0e
#define lfork 0x0f
#define aff 0x10

typedef struct vm_s vm_t;
typedef struct champion_s champion_t;

typedef struct function_s {
    void (*exec_instr)(vm_t *vm, champion_t *champ);
} function_t;

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

typedef struct champion_s {
    int prog_number;
    int load_address;
    int alive;
    bool is_dead;
    int nbr_live;
    char *path;
    header_t *header;
    char *body;
    int pc;
    int carry;
    int *r;
    bool is_loading;
    int load_cycle;
    bool is_invalid_register;
} champion_t;

typedef struct vm_s {
    int nbr_cycle_to_print;
    int nbr_cycle;
    int prog_number;
    int load_address;
    int nb_champ;
    char *arena;
    int cycles;
    int cycle_to_die;
    int nbr_live;
    list_t *champ_list;
    function_t *exec_func;
    char *r;
    champion_t *winner;
} vm_t;

void push(list_t **list, void *data);
void display_help(void);
void display_arena(vm_t *vm);
void display_vm_data(vm_t *vm);
int handling_error(int argc, char **argv, vm_t *vm);
void fill_champ_list(vm_t *vm);
int my_strcory(char *dest, champion_t *champ);
int init_arena(vm_t *vm);
int verif_whos_alive(vm_t *vm);
int nb_of_live(vm_t *vm);
void check_alive(vm_t *vm);
int get_bit_at(int x, int n);
int is_index(char instruction, int pos);
int get_nb_byte(char instruction, char bytecode);
void set_bit_at(char *x, int n, int value);
void set_bit_int_at(int *x, int n, int value);
int get_live_params(vm_t *vm, champion_t *champion);
list_t *get_champion_with_prog_number(list_t *champ_list, int prog_number);
void write_four_bytes(char *to_write, int pc, int param);
int get_value_of_param(vm_t *vm, int type, int pc);
int analyze_type(int type, int *act_pc, champion_t *champion, vm_t *vm);
int main_loop(vm_t *vm, int cycle_to_stop);
int get_value_indirect(vm_t *vm, champion_t *champion, int copy);
void init_exec_func(vm_t *vm);
champion_t *copy_champion(champion_t *champion);
int is_valid_instruction(vm_t *vm, champion_t *champ);
int is_valid_register(int reg, champion_t *champ);
char *get_arena_at_cycle(int argc, char **argv, int cycle);

void exec_live(vm_t *vm, champion_t *champ);
void exec_ld(vm_t *vm, champion_t *champ);
void exec_st(vm_t *vm, champion_t *champ);
void exec_add(vm_t *vm, champion_t *champ);
void exec_sub(vm_t *vm, champion_t *champ);
void exec_and(vm_t *vm, champion_t *champ);
void exec_or(vm_t *vm, champion_t *champ);
void exec_xor(vm_t *vm, champion_t *champ);
void exec_zjmp(vm_t *vm, champion_t *champ);
void exec_ldi(vm_t *vm, champion_t *champ);
void exec_sti(vm_t *vm, champion_t *champ);
void exec_fork(vm_t *vm, champion_t *champ);
void exec_lld(vm_t *vm, champion_t *champ);
void exec_lldi(vm_t *vm, champion_t *champ);
void exec_lfork(vm_t *vm, champion_t *champ);
void exec_aff(vm_t *vm, champion_t *champ);
