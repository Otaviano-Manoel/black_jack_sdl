#pragma once

#include <Game_Manager.h>

typedef struct Gif
{
    SDL_Surface *surfaces[120];
    int length;
    int current;
    int duplicate;
    int duplicate_current;

    void (*UpdateFrame)(SDL_Renderer *renderer, Object *obj);
} Gif;

void Gif_Init(Object *obj, char *file, char *prefix, int length, int duplicate, int width, int height);
void Gif_Free(Gif *gif);