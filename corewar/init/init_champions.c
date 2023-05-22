/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** init_champions.c
*/

#include "init.h"

champion_t *new_champ(char *champ_path, vm_t *vm)
{
    champion_t *champ = malloc(sizeof(champion_t));

    champ->path = champ_path;
    champ->prog_number = vm->prog_number;
    champ->load_address = vm->load_address;
    champ->pc = vm->load_address;
    champ->body = NULL;
    champ->alive = true;
    champ->nbr_live = 0;
    champ->header = NULL;
    champ->carry = 0;
    champ->r = malloc(sizeof(int) * 17);
    champ->r[1] = champ->prog_number;
    return champ;
}

bool check_champions_exist(char *champ_path, vm_t *vm)
{
    int fd = open(champ_path, O_RDONLY);
    int path_len = my_strlen(champ_path);

    if (fd == -1) {
        close(fd);
        return false;
    }
    close(fd);
    if (champ_path[path_len - 1] != 'r' ||
        champ_path[path_len - 2] != 'o' ||
        champ_path[path_len - 3] != 'c' ||
        champ_path[path_len - 4] != '.')
        return false;
    push(&vm->champ_list, new_champ(champ_path, vm));
    vm->nb_champ++;
    return true;
}

int next_check_valid_champ(char **argv, int id, vm_t *vm)
{
    int flag_return = 0;

    flag_return = check_next_prog_num(argv, id, vm);
    if (flag_return == 1)
        return 2;
    if (flag_return == 84)
        return 84;
    flag_return = check_champions_exist(argv[id], vm);
    if (!flag_return)
        return 84;
    return 0;
}

int check_valid_champ(char **argv, int id, vm_t *vm)
{
    int flag_return = 0;
    int i = 0;
    int next = 0;

    for (int j = 0; j != 3; j++) {
        flag_return = check_next_address(argv, id + i, vm);
        if (flag_return == 1) {
            i += 2;
            continue;
        }
        if (flag_return == 84)
            return 84;
        next = next_check_valid_champ(argv, id + i, vm);
        if (next == 84)
            return 84;
        if (next == 0)
            return i;
        i += next;
    }
    return 84;
}
