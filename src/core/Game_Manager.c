#include <Game_Manager.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

static void GetPathAssets(GameManager *this);

GameManager *GameManager_Init()
{
    GameManager *this = SDL_malloc(sizeof(GameManager));
    GetPathAssets(this);

    this->isEnableTextInput = SDL_FALSE;
    this->quit = SDL_FALSE;
    this->gameConfig = GameConfig_Init();
    SceneManager_Init(this);
    this->gamePlay = Game_Play_Init();
    return this;
}

static void GetPathAssets(GameManager *this)
{
    this->assets = GetPath(1024);

    char *path = this->assets;

    strcat(path, "/assets/");
}

void Game_Manager_Free(GameManager *this)
{
    SDL_free(this->assets);
    GamePlay_Free(this->gamePlay);
    SDL_free(this->gamePlay);
    Scene_Manager_Free(this->sceneManager);
    SDL_free(this->sceneManager);
    SDL_free(this->gameConfig);
}