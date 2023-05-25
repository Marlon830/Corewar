/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** server.c
*/

#include "server.h"

void next_server(int serverSocket, struct sockaddr_in clientAddress)
{
    char *ip = get_ip();
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket;

    printf("Adresse IP du serveur : %s\n", ip);
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress,
    &clientAddressLength);
    if (clientSocket < 0)
        exit(EXIT_FAILURE);
    printf("Client connecté !\n");
    if (send(clientSocket, "Connected", strlen("Connected"), 0) < 0)
        exit(EXIT_FAILURE);
    close(serverSocket);
    close(clientSocket);
}

int main(void)
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
    sizeof(serverAddress)) < 0)
        exit(EXIT_FAILURE);
    if (listen(serverSocket, 1) < 0)
        exit(EXIT_FAILURE);
    next_server(serverSocket, clientAddress);
    return main();
}
