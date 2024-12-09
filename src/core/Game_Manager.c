#include <Game_Manager.h>
#include <unistd.h>

static void GetPathAssets(GameManager *this);

GameManager *GameManager_Init()
{
    GameManager *this = malloc(sizeof(GameManager));
    this->gameConfig = GameConfig_Init();
    this->sceneManager = SceneManager_Init();
    this->gamePlay = Game_Play_Init();
    GetPathAssets(this);
    this->isEnableTextInput = SDL_FALSE;
    this->quit = SDL_FALSE;
    this->sceneManager->Init_SDL_Mixer(this);

    return this;
}

static void GetPathAssets(GameManager *this)
{
    this->assets = GetPath(1024);

    char *path = this->assets;
    size_t len = strlen(path);

    path[len - 3] = '\0';

    strcat(path, "assets/");
}

void Game_Manager_Free(GameManager *this)
{
    SDL_free(this->assets);
    Scene_Manager_Free(this->sceneManager);
    SDL_free(this->sceneManager);
    GamePlay_Free(this->gamePlay);
    SDL_free(this->gamePlay);
    SDL_free(this->gameConfig);
}