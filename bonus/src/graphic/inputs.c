/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** inputs.c
*/

#include "corewar.h"

void logo_input(app_t *app)
{
    if (app->framesCounter > 130) {
        StopMusicStream(app->logo->music);
        PlayMusicStream(app->menu->music);
        app->screen = MENU;
    }
}

void menu_input(app_t *app)
{
    update_buttons(app, app->menu->buttons);
}

void text_box_input(app_t *app)
{
    if (app->connect->mouseOnText)
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (app->connect->letterCount < 16)) {
            app->connect->ip[app->connect->letterCount] = (char)key;
            app->connect->ip[app->connect->letterCount + 1] = '\0';
            app->connect->letterCount++;
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        app->connect->letterCount--;
            if (app->connect->letterCount < 0) app->connect->letterCount = 0;
            app->connect->ip[app->connect->letterCount] = '\0';
    }
}

void connect_input(app_t *app)
{
    update_buttons(app, app->connect->buttons);
    if (CheckCollisionPointRec(GetMousePosition(), app->connect->textBox))
        app->connect->mouseOnText = true;
    else
        app->connect->mouseOnText = false;
    if (app->connect->mouseOnText && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        app->is_input = true;
    else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    if (app->is_input)
        text_box_input(app);
}

void inputs(app_t *app)
{
    if (IsKeyPressed(KEY_F11))
        ToggleFullscreen();
    app->mousePoint = GetMousePosition();
    switch (app->screen) {
        case LOGO: logo_input(app); break;
        case MENU: menu_input(app); break;
        case CONNECT: connect_input(app); break;
        case COREWAR: corewar_input(app); break;
        default: break;
    }
    app->framesCounter++;
}
