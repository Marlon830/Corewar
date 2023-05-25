/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** ray.h
*/

#pragma once

#include "raylib.h"
#include "rlgl.h"
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

#define RAYLIB_NEW_RLGL
#define LETTER_BOUNDRY_SIZE     0.25f
#define TEXT_MAX_LAYERS         32
#define LETTER_BOUNDRY_COLOR    VIOLET

typedef struct param_s {
    int codepoint;
    float textOffsetX;
    float textOffsetY;
    int index;
    float scale;
} param_t;

typedef struct char_info_s {
    Vector3 position;
    float x;
    float y;
    float z;
    float tx;
    float ty;
    float tw;
    float th;
    float width;
    float height;
} char_info_t;

typedef struct d_text_s {
        Vector3 position;
        Color tint;
        float fontSize;
        float fontSpacing;
        float lineSpacing;
        bool backface;
} d_text_t;

typedef struct color_mode_s {
    Color cube_color;
    Color wire_color;
    Color text_color;
    Color background;
} color_mode_t;

void drawtext3d(d_text_t *param, const char *text);
char_info_t *init_char_info(Rectangle srcRec, Font font, Vector3 position);
