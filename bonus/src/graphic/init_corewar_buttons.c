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
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/pause_corewar.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/stop_corewar.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/cycle_l.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/cycle_r.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/speed_l.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
    tmp = create_button("src/graphic/assets/speed_r.png",
    (Vector2){app->screenWidth  - 150, app->screenHeight - 150},
    (Vector2){300, 300}, 1);
    tmp->clicked = &ratiomarlon;
    push(&corewar->buttons, tmp);
}
