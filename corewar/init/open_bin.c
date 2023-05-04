/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** open_bin.c
*/

#include "init.h"

unsigned int little_to_big_endian(int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
    ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}

header_t *get_bin_header(char *path)
{
    int fd = open(path, O_RDONLY);
    header_t *header = malloc(sizeof(header_t));

    read(fd, header, sizeof(header_t));
    close(fd);
    if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
        header->magic = little_to_big_endian(header->magic);
        header->prog_size = little_to_big_endian(header->prog_size);
    }
    return header;
}

char *get_bin_body(champion_t *champ)
{
    int fd = open(champ->path, O_RDONLY);
    header_t header;
    char *body = malloc(sizeof(char) * champ->header->prog_size);

    read(fd, &header, sizeof(header_t));
    read(fd, body, champ->header->prog_size);
    close(fd);
    return body;
}

void open_bin(champion_t *champ)
{
    champ->header = get_bin_header(champ->path);
    champ->body = get_bin_body(champ);
}
