/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** main.c
*/

#include "asm.h"

int main(int argc, char *argv[])
{
    compil_t *compil = init_compil_struct();

    if (argc != 2) {
        write_error(BOLD"Invalid number of arguments\n"NC, -1, NULL);
        write_help();
        return 84;
    }
    if (!my_strcmp(argv[1], "-h"))
        return write_help();
    if (check_error(argv) == 84)
        return 84;
    get_all_labels_info(compil, argv);
    compile_champion(compil, argv);
    return 0;
}
