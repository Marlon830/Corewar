/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** init_champions.c
*/

#include "corewar.h"

champion_t *new_champ(char *champ_path)
{
    champion_t *champ = malloc(sizeof(champion_t));
    champ->path = champ_path;
    champ->prog_number = 0;
    champ->load_address = 0;
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
    push(&vm->champ_list, new_champ(champ_path));
    vm->nb_champ++;
    return true;
}
