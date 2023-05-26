/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** server.h
*/

#pragma once

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

#define PORT 54321
#define BUFFER_SIZE 1024

typedef enum packet_type {
    CYCLE = 0,
    OTHER
} packet_type;

typedef struct server_s {
    char *arena;
    char *champ_bytes;
    int *pc;
} server_t;

typedef struct client_s {
    enum packet_type type;
    int value;
} client_t;

char *get_ip(void);
