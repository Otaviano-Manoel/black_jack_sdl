#pragma once

#include <Game_Manager.h>

#define MAX_LENGTH_TAG 32
#define TAG_BACKGROUND "background"

typedef struct Object
{
    char tag[MAX_LENGTH_TAG];
    int layer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect *rect;
    SDL_Rect *rectOrigin;
    Gif *gif;

    Text *text;

    SDL_bool isHover, isButton, isVisible;
    int xEnd, yEnd;
    Uint8 opacity;

    void (*SetTag)(Object *obj, char tag[MAX_LENGTH_TAG]);
    void (*Create_Rect)(Window *window, struct Object *obj, int x, int y, int width, int height);
    void (*Create_Surface)(Object *obj, const char *file, int width, int height, SDL_bool isSetColor);
    void (*Create_Texture)(SDL_Renderer *renderer, Object *obj);
    void (*SetColorKey)(Object *obj, Uint8 r, Uint8 g, Uint8 b);

    void (*OnHover)(GameManager *manager, struct Object *this);
    void (*OnLeave)(GameManager *manager, struct Object *this);
    void (*OnAnimClick)(GameManager *manager, struct Object *this);
    void (*OnClick)(GameManager *manager, struct Object *this);
    void (*LoadAnimatedGIF)(Object *obj, const char *filename);

} Object;

Object *Obj_Init();
Object *Obj_CreateWithImage(GameManager *manager, const char *file, char *tag, int layer, int x, int y, int width, int height, Uint8 opacity, SDL_bool isSetColor, SDL_bool isButton, void (*OnClick)(GameManager *manager, struct Object *this));
Object *Obj_CreateWithText(GameManager *manager, Object *objDest, SDL_Color textColor, char *writer, char *fileFont, char *tag, int layer, int ptsize, int x, int y, int lineSpace, Uint8 opacity);
Object *Obj_CreateWithGif(GameManager *manager, char *file, char *prefix, char *tag, Uint8 opacity, int length, int duplicate, int x, int y, int width, int height, int layer);
void Obj_Free(Object *obj);