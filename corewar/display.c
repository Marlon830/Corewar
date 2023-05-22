/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** display.c
*/

#include "corewar.h"

void display_help(void)
{
    write(1, "Help: voilà\n", 13);
}

void display_line_pos(vm_t *vm, int i)
{
    char *hex = convert_to_hexa(i);

    if (i == 0) {
        write(1, "0    : ", 7);
        return;
    }
    write(1, "\n", 1);
    write(1, hex, my_strlen(hex));
    for (int i = 0; i != 4 - my_strlen(hex); i++)
        write(1, " ", 1);
    write(1, " : ", 3);
}

void display_arena(vm_t *vm)
{

    for (int i = 0; i != MEM_SIZE; i++) {
        if (i % 32 == 0) {
            display_line_pos(vm, i);
        }
        if (vm->arena[i] == 0) {
            write(1, "00 ", 3);
        } else {
            unsigned char chr = (unsigned char)vm->arena[i];
            char hexa[3];
            hexa[0] = "0123456789ABCDEF"[chr / 16];
            hexa[1] = "0123456789ABCDEF"[chr % 16];
            hexa[2] = ' ';
            write(1, hexa, 3);
        }
    }
    write(1, "\n", 1);
}
