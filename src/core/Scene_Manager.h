#pragma once

#include <Game_Manager.h>

#define MAX_WIDTH_WINDOW 1280
#define MAX_HEIGHT_WINDOW 720
#define MAX_FPS 60
#define FRAME_TIME (1000 / MAX_FPS)

typedef struct SceneManager
{
    int layerCurrent;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;

    struct Scene *current;
    SDL_bool isCurrentSet;

    void (*ChangeScene)(struct GameManager *, struct Scene *);

    void (*Start)(struct GameManager *);
    void (*Update)(struct GameManager *);
    void (*Quit)(struct GameManager *);
} SceneManager;

SceneManager *SceneManager_Init();