/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** socket.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#pragma once

typedef struct packet_s {
    char *arena;
    char *champ_bytes;
    int *pc;
} packet_t;
