#include <GameManager.h>
#include <unistd.h>

static void GetPathAssets(GameManager *this);

GameManager *GameManager_Init()
{
    GameManager *this = malloc(sizeof(GameManager));
    this->gameConfig = GameConfig_Init();
    this->sceneManager = SceneManager_Init();
    GetPathAssets(this);

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