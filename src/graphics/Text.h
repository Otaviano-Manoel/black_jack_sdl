#pragma once

#include <Game_Manager.h>

typedef struct Text
{
    TTF_Font *font;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect *textRect;

    SDL_bool isTextLoaded;

    void (*Destroy)(Text *text);
    void (*SetFont)(struct Text *text, char *file, int ptsize);
    void (*SetColor)(SDL_Renderer *renderer, struct Text *text, char *writer, SDL_Color textColor);
    void (*SetPosition)(struct Text *text, int x, int y);
    void (*InitFull)(SDL_Renderer *renderer, Text *text, char *file, int ptsize, char *writer, SDL_Color textColor, int x, int y);
} Text;

Text *Text_Init();
