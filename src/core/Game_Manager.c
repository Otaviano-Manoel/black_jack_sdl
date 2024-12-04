#include <Game_Manager.h>
#include <unistd.h>

static void GetPathAssets(GameManager *this);

GameManager *GameManager_Init()
{
    GameManager *this = malloc(sizeof(GameManager));
    this->gameConfig = GameConfig_Init();
    this->sceneManager = SceneManager_Init();
    GetPathAssets(this);
    this->player[0] = Player_Init();
    this->player[1] = Player_Init();
    this->deck = Deck_Init();
    this->isEnableTextInput = SDL_FALSE;
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
    SDL_free(this->player[0]);
    SDL_free(this->player[1]);
    SDL_free(this->gameConfig);
    Deck_Free(this->deck);
    SDL_free(this->deck);
}