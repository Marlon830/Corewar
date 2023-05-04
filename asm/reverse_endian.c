/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** reverse_endian.c
*/

#include "asm.h"

int reverse_endian(int x)
{
    if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
        return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
        ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
    }
    return x;
}
