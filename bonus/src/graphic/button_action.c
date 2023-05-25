/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** button_action.c
*/

#include "corewar.h"
#include "socket.h"

void play_button_clicked(app_t *app)
{
    app->screen = CONNECT;
    PlaySound(app->menu->fxBoom);
}

void quit_button_clicked(app_t *app)
{
    app->loop = false;
}

void socket_button_clicked(app_t *app)
{
    app->screen = COREWAR;
    PlaySound(app->menu->fxBoom);
    DisableCursor();
}

void next_connect_button_clicked(app_t *app, int clientSocket,
struct sockaddr_in serverAddress, char buffer[1024])
{
    if (connect(clientSocket, (struct sockaddr *)&serverAddress,
    sizeof(serverAddress)) < 0) {
        app->connect->text = "Erreur lors de la connexion au serveur";
        app->screen = CONNECT;
    }
    read(clientSocket, buffer, 1024);
    app->socket->text = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(app->socket->text, buffer);
    close(clientSocket);
}

void connect_button_clicked(app_t *app)
{
    int clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[1024] = {0};

    app->screen = SOCKET;
    app->ip = app->connect->ip;
    PlaySound(app->menu->fxBoom);
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        app->connect->text = "Erreur lors de la création de la socket";
        app->screen = CONNECT;
    }
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(app->ip);
    serverAddress.sin_port = htons(PORT);
    next_connect_button_clicked(app, clientSocket, serverAddress, buffer);
}
