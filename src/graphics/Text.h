#pragma once

#include <Game_Manager.h>

typedef struct Text
{
    TTF_Font *font;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    SDL_Rect *textRect;
    SDL_Rect *textRectOrigin;
    SDL_Color color;

    SDL_bool isTextLoaded;

    char *text;
    char *file;
    int ptSize;

    void (*Destroy)(Text *text);
    void (*SetFont)(Window *window, struct Text *text, char *file, int ptsize);
    void (*SetText)(SDL_Renderer *renderer, struct Text *text, char *writer, SDL_Color textColor);
    void (*SetPosition)(Window *window, Object *obj, struct Text *text, int x, int y);
    void (*InitFull)(SceneManager *sceneManager, Object *obj, Text *text, char *file, int ptsize, char *writer, SDL_Color textColor, int x, int y);
} Text;

Text *Text_Init();
