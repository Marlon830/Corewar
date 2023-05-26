/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** corewar.h
*/

#include "ray.h"
#include "socket.h"
#include <stdio.h>

#pragma once

typedef struct app_s app_t;

typedef enum game_screen {
    LOGO = 0,
    MENU,
    CONNECT,
    SOCKET,
    COREWAR
} game_screen;

typedef struct list_s {
    void *elt;
    struct list_s *next;
} list_t;

typedef struct logo_s {
    Texture2D gnuLogo;
    Music music;
    list_t *sprites;
} logo_t;

typedef struct button_s {
    Texture2D texture;
    float frameWidth;
    float frameHeight;
    Rectangle frameRec;
    Rectangle destRec;
    int state;
    int nbFrames;
    bool action;
    void (*clicked)(app_t *app);
} button_t;

typedef struct sprite_s {
    Texture2D texture;
    float frameWidth;
    float frameHeight;
    Rectangle frameRec;
    Rectangle destRec;
    int nbFrames;
    int current_frame;
    int anim_frame;
} sprite_t;

typedef struct menu_s {
    Texture2D background;
    Texture2D logo;
    list_t *buttons;
    Music music;
    Sound fxBoom;
    float rotation;
    int side_rot;
    int side_posy;
    float posy;

} menu_t;

typedef struct connect_s {
    Texture2D background;
    list_t *buttons;
    Sound fxBoom;
    char *ip;
    char *text;
    int letterCount;
    Rectangle textBox;
    bool mouseOnText;
} connect_t;

typedef struct socket_s {
    Texture2D background;
    list_t *buttons;
    char *text;
    Sound fxBoom;
} socket_t;

typedef struct corewar_s {
    color_mode_t colorMode;
    Camera3D camera;
    d_text_t *param;
    char *arena;
    int need_get;
} corewar_t;

typedef struct app_s {
    int screenWidth;
    int screenHeight;
    game_screen screen;
    pthread_t thread;
    int framesCounter;
    int display;
    logo_t *logo;
    menu_t *menu;
    connect_t *connect;
    socket_t *socket;
    corewar_t *corewar;
    Vector2 mousePoint;
    bool loop;
    char *ip;
    packet_t *packet;
} app_t;

void inputs(app_t *app);
void socket_input(app_t *app);
void corewar_input(app_t *app);
void draw(app_t *app);
void draw_buttons(list_t *buttons);
void draw_sprites(app_t *app, list_t *sprites);
void draw_connect_textbox(app_t *app);
void draw_socket(app_t *app);
void draw_connect(app_t *app);
void draw_menu(app_t *app);
void draw_logo(app_t *app);
void draw_corewar(app_t *app);

button_t *create_button(char *path, Vector2 pos, Vector2 frameSize,
int nbFrames);
void update_buttons(app_t *app, list_t *buttons);
void play_button_clicked(app_t *app);
void quit_button_clicked(app_t *app);
void connect_button_clicked(app_t *app);
void socket_button_clicked(app_t *app);

sprite_t *create_sprite(char *path, Vector2 pos,
Vector2 frameSize, int nbFrames);
void get_arena(app_t *app);

app_t *init_app(void);
menu_t *init_menu(app_t *app);
logo_t *init_logo(void);
connect_t *init_connect(app_t *app);
socket_t *init_socket(app_t *app);
corewar_t *init_corewar(app_t *app);

void push(list_t **list, void *elt);
void charToHex(char c, char hexa[3]);
