/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** init.c
*/

#include "corewar.h"
#include "socket.h"

app_t *init_app(void)
{
    app_t *app = malloc(sizeof(app_t));
    app->screenWidth = 1920;
    app->screenHeight = 1080;
    app->screen = LOGO;
    app->framesCounter = 0;
    app->display = GetCurrentMonitor();
    InitAudioDevice();
    InitWindow(app->screenWidth, app->screenHeight, "Corewar - The Game");
    SetTargetFPS(60);
    ToggleFullscreen();
    app->mousePoint = (Vector2){0.0f, 0.0f};
    app->loop = true;
    app->logo = init_logo();
    app->menu = init_menu(app);
    app->connect = init_connect(app);
    app->socket = init_socket(app);
    app->corewar = init_corewar(app);
    app->packet = malloc(sizeof(server_t));
    app->next_cycle = 10;
    memset(app->packet->arena, 0, 6144);
    memset(app->packet->champ_bytes, 0, 6144);
    return app;
}

logo_t *init_logo(void)
{
    logo_t *logo = malloc(sizeof(logo_t));
    sprite_t *tmp = NULL;

    logo->gnuLogo = LoadTexture("src/graphic/assets/gnu-logo.png");
    logo->music = LoadMusicStream("src/graphic/assets/slipping.ogg");
    logo->sprites = NULL;
    tmp = create_sprite("src/graphic/assets/loading.png",
    (Vector2){750, 650}, (Vector2){400, 400}, 5);
    push(&logo->sprites, tmp);
    return logo;
}

menu_t *init_menu(app_t *app)
{
    menu_t *menu = malloc(sizeof(menu_t));
    button_t *tmp = NULL;
    menu->background = LoadTexture("src/graphic/assets/background.png");
    menu->logo = LoadTexture("src/graphic/assets/logo.png");
    menu->music = LoadMusicStream("src/graphic/assets/metal.ogg");
    menu->fxBoom = LoadSound("src/graphic/assets/boom.ogg");
    menu->buttons = NULL;
    menu->rotation = 0; menu->posy = 0;
    menu->side_rot = 1; menu->side_posy = 1;
    tmp = create_button("src/graphic/assets/play_button.png",
    (Vector2){app->screenWidth / 2 - 150, app->screenHeight / 2 - 75},
    (Vector2){300, 150}, 1);
    tmp->clicked = &play_button_clicked;
    push(&menu->buttons, tmp);
    tmp = create_button("src/graphic/assets/quit_button.png",
    (Vector2){app->screenWidth / 2 - 150, app->screenHeight / 2 + 75},
    (Vector2){300, 150}, 1);
    tmp->clicked = &quit_button_clicked;
    push(&menu->buttons, tmp);
    return menu;
}

connect_t *init_connect(app_t *app)
{
    connect_t *connect = malloc(sizeof(connect_t));
    button_t *tmp = NULL;

    connect->background = LoadTexture("src/graphic/assets/background.png");
    connect->fxBoom = LoadSound("src/graphic/assets/boom.mp3");
    connect->buttons = NULL;
    connect->ip = malloc(sizeof(char) * 16);
    connect->ip[0] = '\0';
    connect->letterCount = 0;
    connect->mouseOnText = false;
    connect->text = "Enter the server IP";
    connect->textBox = (Rectangle){app->screenWidth / 2.0f - 250,
    app->screenHeight / 2.0f - 100, 500, 50};
    tmp = create_button("src/graphic/assets/quit_button.png",
    (Vector2){app->screenWidth / 2 - 150, app->screenHeight / 2 + 75},
    (Vector2){300, 150}, 1);
    tmp->clicked = &connect_button_clicked;
    push(&connect->buttons, tmp);
    return connect;
}

socket_t *init_socket(app_t *app)
{
    socket_t *sockets = malloc(sizeof(socket_t));
    button_t *tmp = NULL;

    (void)app;
    sockets->background = LoadTexture("src/graphic/assets/background.png");
    sockets->fxBoom = LoadSound("src/graphic/assets/boom.ogg");
    sockets->buttons = NULL;
    tmp = create_button("src/graphic/assets/play_button.png",
    (Vector2){app->screenWidth / 2 - 150, app->screenHeight / 2 + 175},
    (Vector2){300, 150}, 1);
    tmp->clicked = &socket_button_clicked;
    push(&sockets->buttons, tmp);
    return sockets;
}
