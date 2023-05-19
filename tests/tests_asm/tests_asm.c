/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** tests_asm.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test, test_for_test) {
    compil_t *compil = init_compil_struct();
    char **argv = malloc(sizeof(char *) * 3);

    for (int i = 0; i < 3; i++)
        argv[i] = malloc(sizeof(char) * 17);
    argv[0] = "./asm";
    argv[1] = "../tests/tests_asm/tyron.s";
    argv[2] = NULL;
    get_all_labels_info(compil, argv);
    compile_champion(compil, argv);
    free(argv);
}
