/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** draw_text_3d
*/

#include "corewar.h"

void drawtcp(Font font, d_text_t *param, char_info_t *c)
{
    rlCheckRenderBatchLimit(4 + 4 * param->backface);
    rlSetTexture(font.texture.id);
    rlPushMatrix();
    rlTranslatef(c->position.x, c->position.y, c->position.z);
    rlBegin(RL_QUADS);
    rlColor4ub(param->tint.r, param->tint.g, param->tint.b, param->tint.a);
    rlNormal3f(0.0f, 1.0f, 0.0f);
    rlTexCoord2f(c->tx, c->ty); rlVertex3f(c->x, c->y, c->z);
    rlTexCoord2f(c->tx, c->th); rlVertex3f(c->x, c->y, c->z + c->height);
    rlTexCoord2f(c->tw, c->th); rlVertex3f(c->x + c->width, c->y, c->z +
    c->height);
    rlTexCoord2f(c->tw, c->ty); rlVertex3f(c->x + c->width, c->y, c->z);
    if (param->backface) {
        rlNormal3f(0.0f, -1.0f, 0.0f);
        rlTexCoord2f(c->tx, c->ty); rlVertex3f(c->x, c->y, c->z);
        rlTexCoord2f(c->tw, c->ty); rlVertex3f(c->x + c->width, c->y, c->z);
        rlTexCoord2f(c->tw, c->th); rlVertex3f(c->x + c->width, c->y, c->z +
        c->height);
        rlTexCoord2f(c->tx, c->th); rlVertex3f(c->x, c->y, c->z + c->height);
    }
}

void drawtcp_bis(Font font, d_text_t *param, char_info_t *char_info)
{
    drawtcp(font, param, char_info);
    rlEnd();
    rlPopMatrix();
    rlSetTexture(0);
    free(char_info);
}

void drawtextcodepoint3d(d_text_t *param, int codepoint, Vector3 position,
Font font)
{
    int index = GetGlyphIndex(font, codepoint);
    float scale = param->fontSize / (float)font.baseSize;
    position.x += (float)(font.glyphs[index].offsetX - font.glyphPadding)
    / (float)font.baseSize * scale;
    position.z += (float)(font.glyphs[index].offsetY - font.glyphPadding)
    / (float)font.baseSize * scale;
    Rectangle srcRec = {font.recs[index].x - (float)font.glyphPadding,
    font.recs[index].y - (float)font.glyphPadding,
    font.recs[index].width + 2.0f * font.glyphPadding,
    font.recs[index].height + 2.0f * font.glyphPadding};
    float width = (float)(font.recs[index].width + 2.0f * font.glyphPadding)
    / (float)font.baseSize * scale;
    float height = (float)(font.recs[index].height + 2.0f * font.glyphPadding)
    / (float)font.baseSize * scale;
    if (font.texture.id > 0) {
        char_info_t *char_info = init_char_info(srcRec, font, position);
        char_info->width = width;
        char_info->height = height;
        drawtcp_bis(font, param, char_info);
    }
}

void draw_text_3d_bis(d_text_t *param, Font font, param_t *info)
{
    if ((info->codepoint != ' ') && (info->codepoint != '\t'))
        drawtextcodepoint3d(param, info->codepoint, (Vector3){
        param->position.x + info->textOffsetX, param->position.y,
        param->position.z + info->textOffsetY}, font);
    if (font.glyphs[info->index].advanceX == 0)
        info->textOffsetX += (float)(font.recs[info->index].width +
        param->fontSpacing) / (float)font.baseSize * info->scale;
    else
        info->textOffsetX += (float)(font.glyphs[info->index].advanceX +
        param->fontSpacing) / (float)font.baseSize * info->scale;
}

void drawtext3d(d_text_t *param, const char *text)
{
    int length = TextLength(text);
    param_t info = {0};
    info.textOffsetY = 0.0f, info.textOffsetX = 0.0f;
    Font font = GetFontDefault();
    info.scale = param->fontSize / (float)font.baseSize;
    for (int i = 0; i < length;) {
        int codepointByteCount = 0;
        info.codepoint = GetCodepoint(&text[i], &codepointByteCount);
        info.index = GetGlyphIndex(font, info.codepoint);
        if (info.codepoint == 0x3f)
            codepointByteCount = 1;
        if (info.codepoint == '\n') {
            info.textOffsetY += info.scale + param->lineSpacing /
            (float)font.baseSize * info.scale;
            info.textOffsetX = 0.0f;
        } else {
            draw_text_3d_bis(param, font, &info);
        }
        i += codepointByteCount;
    }
}
