/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** tests_corewar.c
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_nb_byte, basic_bytecode) {
    int ans = get_nb_byte(0x0b, 0x68);

    cr_assert_eq(ans, 7);
}

Test(get_nb_byte, another_bytecode) {
    int ans = get_nb_byte(0x02, 0x90);

    cr_assert_eq(ans, 7);
}
