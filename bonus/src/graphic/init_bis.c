/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** init_bis.c
*/

#include "corewar.h"

//bleu, vert, rose, rouge

color_mode_t **init_color_mode(void)
{
    color_mode_t **color_mode = malloc(sizeof(color_mode_t *) * 5);

    for (int i = 0; i < 6; i++) {
        color_mode[i] = malloc(sizeof(color_mode_t));
        color_mode[i]->cube_color = BLACK;
        color_mode[i]->text_color = DARKPURPLE;
    }
    color_mode[1]->wire_color = BLUE;
    color_mode[2]->wire_color = GREEN;
    color_mode[3]->wire_color = PINK;
    color_mode[4]->wire_color = RED;
    color_mode[5]->wire_color = WHITE;
    color_mode[0]->wire_color = DARKGRAY;
    return color_mode;
}

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
    corewar->colorMode = init_color_mode();
    corewar->camera = (Camera3D){0};
    corewar->camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    corewar->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    corewar->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    corewar->camera.fovy = 45.0f;
    corewar->camera.projection = CAMERA_PERSPECTIVE;
    corewar->need_get = false;
    return corewar;
}
