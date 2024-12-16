#pragma once

#include <Game_Manager.h>

typedef struct Gif
{
    SDL_Surface *surfaces[120];
    int length;
    int current;
} Gif;

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj);
void Gif_Init(Object *obj, char *file, int length, int duplicate, char *prefix);
void Gif_Free(Gif *gif);