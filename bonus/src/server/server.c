/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** server.c
*/

#include "server.h"
#include "corewar.h"
#include <string.h>

void send_arena(int argc, char *argv[], int clientSocket, int cycle)
{
    char *arena = get_arena_at_cycle(argc, argv, cycle);
    server_t server = {0};

    strcpy(server.arena, arena);
    if (arena == NULL || write(clientSocket, &server, sizeof(server)) < 0)
        exit(EXIT_FAILURE);
}

void next_server(int argc, char *argv[], int serverSocket, struct sockaddr_in clientAddress)
{
    char *ip = get_ip();
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket;
    int cycle = 0;
    char *cmd = malloc(sizeof(char) * 1024);
    client_t client;

    memset(cmd, 0, 1024);
    printf("Adresse IP du serveur : %s\n", ip);
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress,
    &clientAddressLength);
    if (clientSocket < 0)
        exit(EXIT_FAILURE);
    while (1) {
        read(clientSocket, &client, sizeof(client));;
        if (client.type == CYCLE) {
            send_arena(argc, argv, clientSocket, client.value);
        }
        // read(clientSocket, cmd, 1024);
        // if (cmd[0] == 'C') {
        //     cycle = atoi(cmd + 1);
        //     send_arena(argc, argv, clientSocket, cycle);
        // }
        // memset(cmd, 0, 1024);
    }
    close(serverSocket);
    close(clientSocket);
}

int main(int argc, char **argv)
{
    int serverSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int reuse = 1;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        exit(EXIT_FAILURE);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuse,
    sizeof(reuse)) < 0)
        exit(EXIT_FAILURE);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress,
    sizeof(serverAddress)) < 0) {
        exit(EXIT_FAILURE);
    }
    if (listen(serverSocket, 1) < 0)
        exit(EXIT_FAILURE);
    next_server(argc, argv, serverSocket, clientAddress);
    return 0;
}
