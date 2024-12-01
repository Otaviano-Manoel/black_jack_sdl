#pragma once

#include <GameManager.h>

#define MAX_LENGTH_TAG 32
#define TAG_BACKGROUND "background"

typedef struct Text Text;

typedef struct Object
{
    char tag[MAX_LENGTH_TAG];
    int layer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect *rect;

    Text *text;

    SDL_bool isHover;
    SDL_bool isButton;
    int width, height;
    int xEnd, yEnd;
    Uint8 opacity;

    void (*Obj_SetImage)(SDL_Renderer *renderer, struct Object *obj, const char *file, int width, int height);
    void (*Obj_ResizeRect)(struct Object *obj, int x, int y, int width, int height);

    void (*OnHover)(GameManager *manager, struct Object *this);
    void (*OnLeave)(GameManager *manager, struct Object *this);
    void (*OnAnimClick)(GameManager *manager, struct Object *this);
    void (*OnClick)(GameManager *manager, struct Object *this);

} Object;

Object Obj_Init();