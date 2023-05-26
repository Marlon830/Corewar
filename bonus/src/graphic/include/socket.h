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

typedef enum packet_type {
    CYCLE = 0,
    OTHER
} packet_type;

typedef struct server_s {
    char arena[6144];
    char champ_bytes[6144];
    int my_errno;
    int live[4];
} server_t;

typedef struct client_s {
    enum packet_type type;
    int value;
} client_t;
