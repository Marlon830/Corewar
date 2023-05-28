/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** inputs_bis.c
*/

#include "corewar.h"
#include "ray.h"

void corewar_input(app_t *app)
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        PlaySound(app->menu->fxBoom);
    if (app->framesCounter % app->next_cycle == 0)
        app->corewar->need_get = true;
    if (IsKeyPressed(KEY_TAB)) {
        if (app->cursor == 0) {
            EnableCursor();
            app->cursor = 1;
        } else {
            DisableCursor();
            app->cursor = 0;
        }
    }
    if (IsKeyPressed(KEY_X)) {
        app->corewar->camera.position = (Vector3){64.0f, 180.0f, 96.0f};
    }
}
