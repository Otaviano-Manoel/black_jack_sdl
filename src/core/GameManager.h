#pragma once

typedef struct GameManager GameManager;
typedef struct Text Text;
typedef struct Object Object;
typedef struct GameConfig GameConfig;

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <File_Utils.h>
#include <SceneManager.h>
#include <Scene.h>
#include <EventManager.h>
#include <Object.h>
#include <Text.h>
#include <GameConfig.h>
#include <ObjectEvent.h>
#include <MenuEvent.h>
#include <Object_Interactions.h>
#include <Graphics_Utils.h>

typedef struct GameManager
{
    char *assets;
    SDL_bool quit;
    SceneManager *sceneManager;
    GameConfig *gameConfig;
} GameManager;

GameManager *GameManager_Init();