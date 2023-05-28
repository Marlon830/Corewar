/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** draw_scene_bis
*/

#include "corewar.h"

void draw_all(app_t *app, pos_t *pos)
{
    char hex[3] = {0};
    color_mode_t *color;
    if (app->corewar->need_get == 1) {
        color = app->corewar->colorMode[(int)app->corewar->prev.champ_bytes[pos->k]];
    } else {
        color = app->corewar->colorMode[(int)app->packet->champ_bytes[pos->k]];
        app->corewar->param->tint = color->text_color;
    }
    DrawCube((Vector3){pos->j, 0.5, pos->i}, 1.0f, 1.0f, 1.0f,
    color->cube_color);
    DrawCubeWires((Vector3){ pos->j, 0.5, pos->i }, 1.0f, 1.0f, 1.0f,
    color->wire_color);
    app->corewar->param->position = (Vector3){pos->j - 0.35, 1.1, pos->i - 0.2};
    if (app->corewar->need_get == 1) {
        charToHex(app->corewar->prev.arena[pos->k], hex);
        drawtext3d(app->corewar->param, hex);
    } else {
        charToHex(app->packet->arena[pos->k], hex);
        drawtext3d(app->corewar->param, hex);
    }
    pos->k += 1;
}

void draw_2d_objects(app_t *app)
{
    for (int i = 0; i != 4; i++) {
        if (app->packet->lives[i] != -1)
            DrawText(TextFormat("Champion %d last live: %d", i + 1,
            app->packet->lives[i]), 10, 10 + (i * 20), 20, WHITE);
    }
    draw_buttons(app->corewar->buttons);
    DrawText(TextFormat("Cycle: %d", app->corewar->cycle_int), 0, 600, 20, WHITE);
    DrawText(TextFormat("Cycle speed: %d", app->corewar->cycle_speed), 0, 620, 20, WHITE);
}
