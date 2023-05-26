/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_arena.c
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ucontext.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <stddef.h>
#include "corewar.h"
#include <string.h>

#define PORT 54321
#define BUFFER_SIZE 1024

void my_revstr(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i = i + 1;
        j = j - 1;
    }
}

char *convert_to_hexa(int nb)
{
    char *hexa = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp = 0;

    for (; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10)
            hexa[i] = tmp + 48;
        else
            hexa[i] = tmp + 55;
        nb = nb / 16;
    }
    if (i == 1)
        hexa[i++] = '0';
    hexa[i] = '\0';
    my_revstr(hexa);
    return hexa;
}

char *itoa(int value, char *result, int base)
{
    if (base < 2 || base > 36) {
        *result = '\0';
        return result;
    }
    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;
    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789"
        "abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void display_line_pos(int i)
{
    char *hex = convert_to_hexa(i);

    if (i == 0) {
        write(1, "0    : ", 7);
        return;
    }
    write(1, "\n", 1);
    write(1, hex, strlen(hex));
    for (int i = 0; i != 4 - strlen(hex); i++)
        write(1, " ", 1);
    write(1, " : ", 3);
}

void display_arena(char *arena)
{

    for (int i = 0; i != 6144; i++) {
        if (i % 32 == 0) {
            display_line_pos(i);
        }
        if (arena[i] == 0) {
            write(1, "00 ", 3);
        } else {
            unsigned char chr = (unsigned char)arena[i];
            char hexa[3];
            hexa[0] = "0123456789ABCDEF"[chr / 16];
            hexa[1] = "0123456789ABCDEF"[chr % 16];
            hexa[2] = ' ';
            write(1, hexa, 3);
        }
    }
    write(1, "\n", 1);
}

void get_arena(app_t *app)
{
    int clientSocket;
    struct sockaddr_in serverAddress;
    client_t client_packet = {0};
    server_t server_packet;
    int cycle_int = 0;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        exit(84);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(app->connect->ip);
    serverAddress.sin_port = htons(PORT);
    if (connect(clientSocket, (struct sockaddr *)&serverAddress,
    sizeof(serverAddress)) < 0)
        exit(84);
    client_packet.type = CYCLE;
    while (1) {
        if (app->corewar->need_get) {
            client_packet.value = cycle_int;
            if (send(clientSocket, &client_packet, sizeof(client_t), 0) < 0)
                exit(84);
            if (read(clientSocket, &server_packet, sizeof(server_t)) < 0)
                exit(84);
            app->corewar->arena = server_packet.arena;
            app->corewar->need_get = 0;
            cycle_int++;
        }
    }
    close(clientSocket);
}