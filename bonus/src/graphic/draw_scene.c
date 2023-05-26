/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** draw_bis.c
*/

#include "corewar.h"

void draw_logo(app_t *app)
{
    Vector2 origin = { app->logo->gnuLogo.width / 2,
    app->logo->gnuLogo.height / 2 };
    Vector2 position = { 1920 / 2 + 250, 1080 / 2 };
    float rotation = (float)app->framesCounter * 4;
    UpdateMusicStream(app->logo->music);
    DrawTexturePro(app->logo->gnuLogo, (Rectangle){0, 0,
    app->logo->gnuLogo.width, app->logo->gnuLogo.height},
    (Rectangle){position.x - origin.x, position.y - origin.y,
    app->logo->gnuLogo.width, app->logo->gnuLogo.height},
    origin, rotation, WHITE);
    draw_sprites(app, app->logo->sprites);
}

void draw_menu(app_t *app)
{
    UpdateMusicStream(app->menu->music);
    DrawTexture(app->menu->background, 0, 0, WHITE);
    Vector2 origin = { app->menu->logo.width / 2,
    app->menu->logo.height / 2 };
    app->menu->rotation += 0.1 * app->menu->side_rot;
    app->menu->posy += 0.5 * app->menu->side_posy;
    if (app->menu->rotation >= 5 || app->menu->rotation <= -5)
        app->menu->side_rot *= -1;
    if (app->menu->posy >= 30 || app->menu->posy <= -30)
        app->menu->side_posy *= -1;
    DrawTexturePro(app->menu->logo, (Rectangle){0, 0,
    app->menu->logo.width, app->menu->logo.height},
    (Rectangle){origin.x, origin.y + app->menu->posy,
    app->menu->logo.width, app->menu->logo.height},
    origin, app->menu->rotation, WHITE);
    draw_buttons(app->menu->buttons);
}

void draw_connect(app_t *app)
{
    UpdateMusicStream(app->menu->music);
    draw_connect_textbox(app);
    DrawText(app->connect->text, 1920 / 2 -
    MeasureText(app->connect->text, 40) / 2, 1080 / 2, 40, WHITE);
    draw_buttons(app->connect->buttons);
}

void draw_socket(app_t *app)
{
    UpdateMusicStream(app->menu->music);
    DrawTexture(app->socket->background, 0, 0, WHITE);
    draw_buttons(app->socket->buttons);
    DrawText(app->socket->text, 1920 / 2 -
    MeasureText(app->socket->text, 40) / 2, 1080 / 2, 40, WHITE);
}

void draw_corewar(app_t *app)
{
    int k = 0;
    char hex[3] = {0};
    color_mode_t *color;
    UpdateCamera(&app->corewar->camera, CAMERA_PERSPECTIVE);
    ClearBackground(BLACK);
    BeginMode3D(app->corewar->camera);
    for (int i = 0; i < 96 * 2; i += 2) {
        for (int j = 0; j < 64 * 2; j += 2) {
            if (app->corewar->need_get == 1) {
                color = app->corewar->colorMode[(int)app->corewar->prev.champ_bytes[k]];
            } else {
                color = app->corewar->colorMode[(int)app->packet->champ_bytes[k]];
                app->corewar->param->tint = color->text_color;
            }
            DrawCube((Vector3){ j, 0.5, i }, 1.0f, 1.0f, 1.0f,
            color->cube_color);
            DrawCubeWires((Vector3){ j, 0.5, i }, 1.0f, 1.0f, 1.0f,
            color->wire_color);
            app->corewar->param->position = (Vector3){j - 0.35, 1.1, i - 0.2};
            if (app->corewar->need_get == 1) {
                charToHex(app->corewar->prev.arena[k], hex);
                drawtext3d(app->corewar->param, hex);
            } else {
                charToHex(app->packet->arena[k], hex);
                drawtext3d(app->corewar->param, hex);
            }
            k++;
        }
    }
    EndMode3D();
}
