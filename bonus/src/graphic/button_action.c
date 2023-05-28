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
    SetTargetFPS(144);
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
    app->screen = COREWAR;
}
