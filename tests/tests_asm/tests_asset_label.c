/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** tests_asset_label
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_elem_label_list, test_if_len_sup_to_1)
{
    label_t *label_list = init_label_list();
    char *name = "test";
    add_elem_label_list(label_list, name, 0);
    add_elem_label_list(label_list, name, 1);
    add_elem_label_list(label_list, name, 2);
    cr_assert_str_eq(label_list->name, "test");
    cr_assert_eq(label_list->pos, 0);
    cr_assert_str_eq(label_list->next->name, "test");
    cr_assert_eq(label_list->next->pos, 1);
    cr_assert_str_eq(label_list->next->next->name, "test");
    cr_assert_eq(label_list->next->next->pos, 2);
}

Test(print_label_list, test_print_not_empty, .init=cr_redirect_stdout)
{
    label_t *label_list = init_label_list();
    char *name = "test";
    int b;

    add_elem_label_list(label_list, name, 0);
    add_elem_label_list(label_list, name, 1);
    add_elem_label_list(label_list, name, 2);
    b = print_label_list(label_list);
    cr_assert_stdout_eq_str("test: 0\ntest: 1\ntest: 2\n");
    cr_assert_eq(b, 1);
}

Test(print_label_list, test_print_empty)
{
    label_t *label_list = init_label_list();
    int b = print_label_list(label_list);
    cr_assert_eq(b, 0);
}
