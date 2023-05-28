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
    int b = false;

    PlayMusicStream(app->logo->music);
    while (!WindowShouldClose() && app->loop) {
        if (app->screen == COREWAR && b == false) {
            app->thread = pthread_create(&app->thread, NULL, (void *)&get_arena, app);
            b = true;
            DisableCursor();
        }
        inputs(app);
        draw(app);
    }
    pthread_join(app->thread, NULL);
    UnloadMusicStream(app->logo->music);
    UnloadMusicStream(app->menu->music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
