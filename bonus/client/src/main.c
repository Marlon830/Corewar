/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main_bonus
*/

#include "my_ray.h"

void main_loop(global_t *global)
{
    UpdateCamera(&global->camera, CAMERA_PERSPECTIVE);
    ClearBackground(global->colorMode.background);
    BeginMode3D(global->camera);
    for (int i = 0; i < 96 * 2; i += 2) {
        for (int j = 0; j < 64 * 2; j += 2) {
            DrawCube((Vector3){ i, 0.5, j }, 1.0f, 1.0f, 1.0f,
            global->colorMode.cube_color);
            DrawCubeWires((Vector3){ i, 0.5, j }, 1.0f, 1.0f, 1.0f,
            global->colorMode.wire_color);
            global->param->position = (Vector3){i - 0.3, 1.1, j - 0.2};
            drawtext3d(global->param, "0 0");
        }
    }
    EndMode3D();
    EndDrawing();
}

int main(void)
{
    global_t *global = init_global(1920, 1080);
    InitWindow(global->screenWidth, global->screenHeight, "Corewar 3D");
    SetTargetFPS(144);
    DisableCursor();
    while (!WindowShouldClose()) {
        main_loop(global);
    }
    CloseWindow();
    return 0;
}
