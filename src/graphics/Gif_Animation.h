#pragma once

#include <Game_Manager.h>

typedef struct Gif
{
    SDL_Surface *surfaces[120];
    int length;
    int current;
} Gif;

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj);
void Create_Gif(Object *obj, char *file, int length, char *prefix);