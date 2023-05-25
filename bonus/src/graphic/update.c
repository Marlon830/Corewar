/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** update.c
*/

#include "corewar.h"

void next_update_button(button_t *button)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        button->state = 2;
    else
        button->state = 1;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        button->action = true;
}

void update_buttons(app_t *app, list_t *buttons)
{
    list_t *tmp = buttons;
    button_t *button = NULL;
    while (tmp != NULL) {
        button = tmp->elt;
        if (CheckCollisionPointRec(GetMousePosition(), button->destRec))
            next_update_button(button);
        else
            button->state = 0;
        if (button->action)
            button->clicked(app);
        button->action = false;
        button->frameRec.x = button->state * button->frameWidth;
        tmp = tmp->next;
    }
}
