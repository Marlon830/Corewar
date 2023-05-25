/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** main.c
*/

#include "corewar.h"

int main(void)
{
    app_t *app = init_app();

    PlayMusicStream(app->logo->music);
    while (!WindowShouldClose() && app->loop) {
        inputs(app);
        draw(app);
    }
    UnloadMusicStream(app->logo->music);
    UnloadMusicStream(app->menu->music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
