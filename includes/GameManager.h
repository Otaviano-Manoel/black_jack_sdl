#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SceneManager.h>
#include <Scene.h>
#include <EventManager.h>
#include <Object.h>
#include <Text.h>
#include <GameConfig.h>

typedef struct GameManager
{
    char *assets;
    SDL_bool quit;
    SceneManager *sceneManager;
    GameConfig *gameConfig;
} GameManager;

GameManager *GameManager_Init();

char *GetFile(GameManager *this, char *nameFile);
