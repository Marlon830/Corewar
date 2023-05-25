/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** init_bis.c
*/

#include "corewar.h"

char_info_t *init_char_info(Rectangle srcRec, Font font, Vector3 position)
{
    char_info_t *char_info = malloc(sizeof(char_info_t));

    char_info->position = position;
    char_info->x = 0.0f;
    char_info->y = 0.0f;
    char_info->z = 0.0f;
    char_info->tx = srcRec.x / font.texture.width;
    char_info->ty = srcRec.y / font.texture.height;
    char_info->tw = (srcRec.x + srcRec.width) / font.texture.width;
    char_info->th = (srcRec.y + srcRec.height) / font.texture.height;
    return char_info;
}

d_text_t *init_text(Vector3 pos, float size)
{
    d_text_t *d_text = malloc(sizeof(d_text_t));

    d_text->tint = DARKGREEN;
    d_text->position = pos;
    d_text->fontSize = size;
    d_text->fontSpacing = 0.0f;
    d_text->lineSpacing = 0.0f;
    d_text->backface = true;
    return d_text;
}

corewar_t *init_corewar(app_t *app)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    (void)app;
    corewar->param = init_text((Vector3){0, 0, 0}, 5.0f);
    corewar->arena = malloc(sizeof(char) * (6144));
    for (int i = 0; i < 6144; i++)
        corewar->arena[i] = 0;
    corewar->colorMode = (color_mode_t){BLACK, GREEN, DARKGREEN, BLACK};
    corewar->camera = (Camera3D){0};
    corewar->camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    corewar->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    corewar->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    corewar->camera.fovy = 45.0f;
    corewar->camera.projection = CAMERA_PERSPECTIVE;
    corewar->need_get = false;
    return corewar;
}
