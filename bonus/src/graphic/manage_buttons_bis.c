/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** manage_buttons_bis
*/

#include "corewar.h"

void speed_l(app_t *app)
{
    if (app->corewar->cycle_speed > -64 && app->corewar->cycle_speed < 0)
        app->corewar->cycle_speed += app->corewar->cycle_speed;
    if (app->corewar->cycle_speed == 1)
        app->corewar->cycle_speed = -1;
    if (app->corewar->cycle_speed > 1)
        app->corewar->cycle_speed -= app->corewar->cycle_speed / 2;
    app->corewar->save_speed = app->corewar->cycle_speed;
}

void speed_r(app_t *app)
{
    if (app->corewar->cycle_speed < 64 && app->corewar->cycle_speed > 0)
        app->corewar->cycle_speed += app->corewar->cycle_speed;
    if (app->corewar->cycle_speed == -1)
        app->corewar->cycle_speed = 1;
    if (app->corewar->cycle_speed < -1)
        app->corewar->cycle_speed -= app->corewar->cycle_speed / 2;
    app->corewar->save_speed = app->corewar->cycle_speed;
}
