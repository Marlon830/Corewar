/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** utils_instructions.c
*/

#include "corewar.h"

void get_nb_byte_bis(char instruction, int *pos, char *count, int temp)
{
    if (is_index(instruction, *pos)) {
        *count += 2;
        *pos += 1;
        return;
    }
    if (temp == 2)
        *count += 4;
    if (temp == 3)
        *count += 2;
    *pos += 1;
}

int get_nb_byte(char instruction, char bytecode)
{
    char count = 0;
    int pos = 0;
    char temp = 0;

    for (int i = 7; i >= 0; i -= 2) {
        temp = 0;
        set_bit_at(&temp, 1, (get_bit_at(bytecode, i)));
        set_bit_at(&temp, 0, (get_bit_at(bytecode, i - 1)));
        if (temp == 0)
            continue;
        if (temp == 1) {
            count++;
            pos++;
            continue;
        }
        get_nb_byte_bis(instruction, &pos, &count, temp);
    }
    return count + 2;
}

void write_four_bytes(char *to_write, int pc, int param)
{
    int k = 3;

    pc = my_modulo(pc, MEM_SIZE);
    for (int i = pc; i < pc + 4; i++) {
        to_write[my_modulo(i, MEM_SIZE)] = 0;
        for (int j = 7; j >= 0; j--) {
            set_bit_at(&to_write[my_modulo(i, MEM_SIZE)], j,
            get_bit_at(param, j + 8 * k));
        }
        k--;
    }
}

int analyze_type(int type, int *act_pc, champion_t *champion, vm_t *vm)
{
    int param = 0;

    if (type == 1) {
        if (!is_valid_register((int) vm->arena[*act_pc], champion)) {
            champion->is_invalid_register = true;
            return 0;
        }
        param = champion->r[(int) vm->arena[*act_pc]];
        *act_pc += 1;
    }
    if (type == 2) {
        param = get_value_of_param(vm, type, *act_pc);
        *act_pc += 4;
    }
    if (type == 3) {
        param = get_value_of_param(vm, type, *act_pc);
        *act_pc += 2;
    }
    return param;
}

champion_t *copy_champion(champion_t *champion)
{
    champion_t *new_champ = malloc(sizeof(*new_champ));
    new_champ->prog_number = champion->prog_number;
    new_champ->load_address = champion->load_address;
    new_champ->alive = champion->alive;
    new_champ->is_dead = champion->is_dead;
    new_champ->nbr_live = champion->nbr_live;
    new_champ->path = champion->path;
    new_champ->header = champion->header;
    new_champ->body = malloc(sizeof(char) * champion->header->prog_size);
    for (int i = 0; i != champion->header->prog_size; i++)
        new_champ->body[i] = champion->body[i];
    new_champ->pc = champion->pc;
    new_champ->carry = champion->carry;
    new_champ->r = malloc(sizeof(int) * 17);
    for (int i = 0; i != 17; i++)
        new_champ->r[i] = champion->r[i];
    new_champ->is_loading = false;
    new_champ->load_cycle = champion->load_cycle;
    new_champ->is_invalid_register = champion->is_invalid_register;
    return new_champ;
}
