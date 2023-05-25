/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** draw.c
*/

#include "corewar.h"

void draw_buttons(list_t *buttons)
{
    list_t *tmp = buttons;

    while (tmp != NULL) {
        button_t *button = tmp->elt;
        DrawTexturePro(button->texture, button->frameRec, button->destRec,
        (Vector2){0, 0}, 0, WHITE);
        tmp = tmp->next;
    }
}

void draw_sprites(app_t *app, list_t *sprites)
{
    list_t *tmp = sprites;

    while (tmp != NULL) {
        sprite_t *sprite = tmp->elt;
        if (app->framesCounter % sprite->anim_frame == 0)
            sprite->current_frame++;
        if (sprite->current_frame == sprite->nbFrames)
            sprite->current_frame = 0;
        sprite->frameRec.x = sprite->current_frame * sprite->frameWidth;
        DrawTexturePro(sprite->texture, sprite->frameRec, sprite->destRec,
        (Vector2){0, 0}, 0, WHITE);
        tmp = tmp->next;
    }
}

void draw_connect_textbox(app_t *app)
{
    DrawTexture(app->connect->background, 0, 0, WHITE);
    if (app->connect->mouseOnText)
        DrawRectangleLines(app->connect->textBox.x, app->connect->textBox.y,
        app->connect->textBox.width, app->connect->textBox.height, WHITE);
    else
        DrawRectangleLines(app->connect->textBox.x, app->connect->textBox.y,
        app->connect->textBox.width, app->connect->textBox.height, WHITE);
    DrawText(app->connect->ip, app->connect->textBox.x + 5,
    app->connect->textBox.y + 8, 40, WHITE);
    if (app->connect->mouseOnText) {
        if (app->connect->letterCount < 10 &&
        ((app->framesCounter / 20) % 2) == 0) {
            DrawText("_",app->connect->textBox.x + 8 +
            MeasureText(app->connect->ip, 40), app->connect->textBox.y +
            12, 40, WHITE);
        }
    }
}

void draw(app_t *app)
{
    BeginDrawing();
    ClearBackground(BLACK);
    switch (app->screen) {
        case LOGO: draw_logo(app); break;
        case MENU: draw_menu(app); break;
        case CONNECT: draw_connect(app); break;
        case SOCKET: draw_socket(app); break;
        case COREWAR: draw_corewar(app); break;
        default: break;
    }
    EndDrawing();
}
