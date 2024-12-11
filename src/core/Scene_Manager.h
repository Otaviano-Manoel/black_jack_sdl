#pragma once

#include <Game_Manager.h>

#define MAX_WIDTH_WINDOW 1280
#define MAX_HEIGHT_WINDOW 720
#define MAX_FPS 60
#define FRAME_TIME (1000 / MAX_FPS)

typedef struct SceneManager
{
    int layerCurrent;
    Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;
    Mix_Music *mix;

    struct Scene *current;
    SDL_bool isCurrentSet;

    void (*ChangeScene)(struct GameManager *, struct Scene *);

    void (*Start)(struct GameManager *);
    void (*Update)(struct GameManager *);
    void (*Quit)(struct GameManager *);
    void (*Init_SDL_Mixer)(GameManager *);
} SceneManager;

SceneManager *SceneManager_Init();
void Scene_Manager_Free(SceneManager *this);