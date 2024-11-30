#pragma once

#include <GameManager.h>

#define MAX_WIDTH_WINDOW 1280
#define MAX_HEIGHT_WINDOW 720
#define MAX_FPS 60
#define FRAME_TIME (1000 / MAX_FPS)

typedef struct GameManager GameManager;
typedef struct Object Object;

typedef struct SceneManager
{
    int layerCurrent;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;

    struct Scene *current;
    SDL_bool isCurrentSet;

    void (*ChangeScene)(GameManager *, struct Scene *);

    void (*Start)(GameManager *);
    void (*Update)(GameManager *);
    void (*Quit)(GameManager *);
} SceneManager;

SceneManager *SceneManager_Init();
int SceneManager_GetObjisHover(struct GameManager *this);