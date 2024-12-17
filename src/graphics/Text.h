#pragma once

#include <Game_Manager.h>

typedef struct Text
{
    TTF_Font *font;
    SDL_Surface *textSurface[50];
    SDL_Texture *textTexture[50];
    SDL_Rect *textRect[50];
    SDL_Rect *textRectOrigin[50];
    SDL_Color color;

    SDL_bool isTextLoaded;

    char *text[50]; // No máximo 50 linhas
    char *file;
    int ptSize, lineSpace, lines;

    void (*SetFont)(Window *window, struct Text *text, char *file, int ptsize);
    void (*SetText)(SDL_Renderer *renderer, struct Text *text, SDL_Color textColor, char *writer, int line);
    void (*SetPosition)(Window *window, Object *obj, struct Text *text, int x, int y, int line);
} Text;

Text *Text_Init();
Text *Text_CreateWithOneLine(GameManager *manager, Object *obj, SDL_Color textColor, char *writer, char *fileFont, int ptsize, int x, int y);
Text *Text_CreateWithMultiLine(GameManager *manager, Object *obj, SDL_Color textColor, char *writer, char *fileFont, int ptsize, int x, int y, int lineSpace);
void Text_Free(Text *text);
