/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** create.c
*/

#include "corewar.h"

button_t *create_button(char *path, Vector2 pos,
Vector2 frameSize, int nbFrames)
{
    button_t *button = malloc(sizeof(button_t));

    button->texture = LoadTexture(path);
    button->frameWidth = frameSize.x;
    button->frameHeight = frameSize.y;
    button->frameRec = (Rectangle){0, 0, button->frameWidth,
    button->frameHeight};
    button->destRec = (Rectangle){pos.x, pos.y, button->frameWidth,
    button->frameHeight};
    button->state = 0;
    button->nbFrames = nbFrames;
    button->action = false;
    return button;
}

sprite_t *create_sprite(char *path, Vector2 pos,
Vector2 frameSize, int nbFrames)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = LoadTexture(path);
    sprite->frameWidth = frameSize.x;
    sprite->frameHeight = frameSize.y;
    sprite->frameRec = (Rectangle){0, 0, sprite->frameWidth,
    sprite->frameHeight};
    sprite->destRec = (Rectangle){pos.x, pos.y, sprite->frameWidth,
    sprite->frameHeight};
    sprite->nbFrames = nbFrames;
    sprite->current_frame = 0;
    sprite->anim_frame = 30;
    return sprite;
}
