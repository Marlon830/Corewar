/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** inputs_bis.c
*/

#include "corewar.h"

void socket_input(app_t *app)
{
    update_buttons(app, app->socket->buttons);
}

void corewar_input(app_t *app)
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        PlaySound(app->menu->fxBoom);
    if (app->framesCounter % app->next_cycle == 0)
        app->corewar->need_get = true;
}
