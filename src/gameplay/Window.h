#pragma once

#include <Game_Manager.h>

typedef struct Window
{
    SDL_Window *window;

    int screenWidth, screenHeight;

    float scaleX, scaleY, scale;

    float offsetX, offsetY;

    SDL_bool isFullScreen;

    void (*UpdateScreen)(Window *this);
} Window;

Window *Window_Init();
void Window_Free(Window *this);