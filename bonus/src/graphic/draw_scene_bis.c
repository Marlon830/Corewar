/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** draw_scene_bis
*/

#include "corewar.h"

void draw_all(app_t *app, pos_t *ps)
{
    char hex[3] = {0};
    color_mode_t *c;
    if (app->corewar->need_get == 1) {
        c = app->corewar->colorMode[(int)app->corewar->
        prev.champ_bytes[ps->k]];
    } else {
        c = app->corewar->colorMode[(int)app->packet->champ_bytes[ps->k]];
        app->corewar->param->tint = c->text_color;
    }
    DrawCube((Vector3){ps->j, 0.5, ps->i}, 1.0, 1.0, 1.0, c->cube_color);
    DrawCubeWires((Vector3){ps->j, 0.5, ps->i}, 1.0, 1.0, 1.0, c->wire_color);
    app->corewar->param->position = (Vector3){ps->j - 0.35, 1.1, ps->i - 0.2};
    if (app->corewar->need_get == 1) {
        chartohex(app->corewar->prev.arena[ps->k], hex);
        drawtext3d(app->corewar->param, hex);
    } else {
        chartohex(app->packet->arena[ps->k], hex);
        drawtext3d(app->corewar->param, hex);
    }
    ps->k += 1;
}

void draw_2d_objects(app_t *app)
{
    for (int i = 0; i != 4; i++) {
        if (app->packet->lives[i] != -1)
            DrawText(TextFormat("Champion %s (%d) last live: %d",
            app->packet->champ_name[i], i + 1, app->packet->lives[i]),
            10, 10 + (i * 20), 20, WHITE);
    }
    draw_buttons(app->corewar->buttons);
    DrawText(TextFormat("Cycle: %d", app->corewar->cycle_int), 0, 600, 20,
    WHITE);
    DrawText(TextFormat("Cycle speed: %d", (app->corewar->is_playing == 1 &&
    app->corewar->is_cycling == 0) ? app->corewar->cycle_speed :
    app->corewar->save_speed),
    0, 620, 20, WHITE);
    if (app->packet->winner != -1)
        DrawText(TextFormat("Winner : champion %s (%d)", app->packet->
        champ_name[app->packet->winner - 1], app->packet->winner),
        150, 540, 90, WHITE);
}
