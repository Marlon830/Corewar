/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** manage_buttons.c
*/

#include "corewar.h"

void play_corewar(app_t *app)
{
    app->corewar->is_playing = true;
    app->corewar->is_stopped = false;
    app->corewar->is_cycling = false;
    app->corewar->cycle_speed = app->corewar->save_speed;
}

void pause_corewar(app_t *app)
{
    app->corewar->is_playing = false;
    app->corewar->is_cycling = false;
    app->corewar->is_stopped = false;
    app->corewar->save_speed = app->corewar->cycle_speed;
}

void stop_corewar(app_t *app)
{
    app->corewar->is_playing = true;
    app->corewar->is_stopped = true;
    app->corewar->is_cycling = false;
    app->corewar->cycle_speed = 1;
    app->corewar->save_speed = 1;
}

void cycle_l(app_t *app)
{
    app->corewar->cycle_speed = -1;
    app->corewar->is_cycling = true;
    app->corewar->is_playing = true;
    app->corewar->is_stopped = false;
}

void cycle_r(app_t *app)
{
    app->corewar->cycle_speed = 1;
    app->corewar->is_cycling = true;
    app->corewar->is_playing = true;
    app->corewar->is_stopped = false;
}
