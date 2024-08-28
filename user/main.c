#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int toggleSliderActive = 1;

int main()
{
    InitWindow(400, 300, "raygui测试");
    SetTargetFPS(240);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        uint16_t fps = GetFPS();
        uint8_t fps_char[16];
        sprintf(fps_char, "FPS: %d", fps);
        GuiLabel((Rectangle){10, 10, 65, 20}, (char *)fps_char);
        GuiToggleSlider((Rectangle){30, 30, 100, 20}, "CLOSE;OPEN", &toggleSliderActive);
        GuiToggleSlider((Rectangle){30, 60, 100, 20}, "CLOSE;OPEN", &toggleSliderActive);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}