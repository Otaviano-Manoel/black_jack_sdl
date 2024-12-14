#pragma once

#include <Game_Manager.h>

typedef struct Gif
{
    int current;
} Gif;

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj);