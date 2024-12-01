#pragma once

#include <GameManager.h>

typedef struct Text
{
    TTF_Font *font;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect *textRect;

    SDL_bool isTextLoaded;

    void (*SetFont)(struct Text *text, char *file, int ptsize);
    void (*SetColor)(GameManager *manager, struct Text *text, char *writer, SDL_Color textColor);
    void (*SetPosition)(struct Text *text, int x, int y);
} Text;

Text *Text_Init();
