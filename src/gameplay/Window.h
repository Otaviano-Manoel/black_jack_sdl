#pragma once

#include <Game_Manager.h>

typedef struct Window
{
    SDL_Window *window;
    int screenWidth, screenHeight;

    float scaleX, scaleY, scale;

    float offsetX, offsetY;
} Window;

Window *Window_Init();