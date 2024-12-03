#pragma once

typedef struct GameManager GameManager;
typedef struct Text Text;
typedef struct Object Object;
typedef struct GameConfig GameConfig;
typedef struct Player Player;
typedef struct Scene Scene;

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <File_Utils.h>
#include <Scene_Manager.h>
#include <Scene.h>
#include <Event_Manager.h>
#include <Object.h>
#include <Text.h>
#include <Game_Config.h>
#include <Object_Event.h>
#include <Menu_Event.h>
#include <Object_Interactions.h>
#include <Graphics_Utils.h>
#include <Setting_Scene.h>
#include <Player.h>

typedef struct GameManager
{
    char *assets;
    SDL_bool quit;
    SceneManager *sceneManager;
    GameConfig *gameConfig;
    Player *player[2];
} GameManager;

GameManager *GameManager_Init();