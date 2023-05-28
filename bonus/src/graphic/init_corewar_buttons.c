/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** init_corewar_buttons
*/

#include "corewar.h"

void init_corewar_buttons(app_t *app, corewar_t *corewar)
{
    button_t *tmp = NULL;

    tmp = create_button("src/graphic/assets/play_corewar.png",
    (Vector2){app->screenWidth  - 600, 0},
    (Vector2){75, 75}, 3);
    tmp->clicked = &play_corewar;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/pause_corewar.png",
    (Vector2){app->screenWidth  - 900, 0},
    (Vector2){75, 75}, 3);
    tmp->clicked = &pause_corewar;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/stop_corewar.png",
    (Vector2){app->screenWidth - 1200, 0},
    (Vector2){75, 75}, 3);
    tmp->clicked = &stop_corewar;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/cycle_l.png",
    (Vector2){app->screenWidth - 900, 300},
    (Vector2){75, 75}, 3);
    tmp->clicked = &cycle_l;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/cycle_r.png",
    (Vector2){app->screenWidth - 300, 300},
    (Vector2){75, 75}, 3);
    tmp->clicked = &cycle_r;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/speed_l.png",
    (Vector2){app->screenWidth - 1500, 0},
    (Vector2){75, 75}, 3);
    tmp->clicked = &speed_l;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/speed_r.png",
    (Vector2){app->screenWidth  - 300, 0},
    (Vector2){75, 75}, 3);
    tmp->clicked = &speed_r;
    push(&corewar->buttons, tmp);
}
