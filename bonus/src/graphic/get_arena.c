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

void get_cycle(app_t *app, int cycle_int, int clientSocket)
{
    client_t client_packet = {0};
    server_t server_packet;
    int bytesReceived = 0;
    int totalBytesExpected = sizeof(server_packet);

    client_packet.type = CYCLE;
    client_packet.value = cycle_int;
    if (write(clientSocket, &client_packet, sizeof(client_packet)) < 0)
        exit(84);
    while (bytesReceived < totalBytesExpected) {
        int remainingBytes = totalBytesExpected - bytesReceived;
        int receivedBytes = read(clientSocket, ((char*)&server_packet) + bytesReceived, remainingBytes);
        if (receivedBytes <= 0)
            exit(84);
        bytesReceived += receivedBytes;
    }
    for (int i = 0; i != 6144; i++) {
        app->packet->arena[i] = server_packet.arena[i];
        app->packet->champ_bytes[i] = server_packet.champ_bytes[i];
    }
    app->packet->my_errno = server_packet.my_errno;
    for (int i = 0; i != 4; i++) {
        app->packet->lives[i] = server_packet.lives[i];
    }
    app->corewar->need_get = 0;
}

void exchange(app_t *app, int cycle_int)
{
    int clientSocket;
    struct sockaddr_in serverAddress;
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        exit(84);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(app->connect->ip);
    serverAddress.sin_port = htons(PORT);
    if (connect(clientSocket, (struct sockaddr *)&serverAddress,
    sizeof(serverAddress)) < 0)
        exit(84);
    while (!app->corewar->need_get);
    app->corewar->prev = *app->packet;
    get_cycle(app, cycle_int, clientSocket);
    close(clientSocket);
}

void get_arena(app_t *app)
{
    int cycle_int = 0;
    while (1) {
        exchange(app, cycle_int);
        cycle_int += 150;
    }
    
}