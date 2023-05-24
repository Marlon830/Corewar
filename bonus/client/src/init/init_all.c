/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_all
*/

#include "my_ray.h"

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

global_t *init_global(int width, int height)
{
    global_t *global = malloc(sizeof(global_t));

    global->param = init_text((Vector3){0, 0, 0}, 5.0f);
    global->screenWidth = width;
    global->screenHeight = height;
    global->colorMode = (color_mode_t){BLACK, GREEN, DARKGREEN, BLACK};
    global->camera = (Camera3D){0};
    global->camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    global->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    global->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    global->camera.fovy = 45.0f;
    global->camera.projection = CAMERA_PERSPECTIVE;
    return global;
}
