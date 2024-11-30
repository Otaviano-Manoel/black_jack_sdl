#include <GameManager.h>
#include <unistd.h>

static char *GetPath(size_t size);
static void GetPathAssets(GameManager *this);

GameManager *GameManager_Init()
{
    GameManager *this = malloc(sizeof(GameManager));
    this->sceneManager = SceneManager_Init();
    GetPathAssets(this);

    return this;
}

char *GetFile(GameManager *this, char *nameFile)
{
    char *imagePath = (char *)malloc(256);
    if (imagePath == NULL)
    {
        SDL_Log("Erro ao alocar memória para o caminho do arquivo.");
        return NULL;
    }

    snprintf(imagePath, 256, "%s%s", this->assets, nameFile);

    return imagePath;
}

static void GetPathAssets(GameManager *this)
{
    this->assets = GetPath(1024);

    char *path = this->assets;
    size_t len = strlen(path);

    path[len - 3] = '\0';

    strcat(path, "assets/");
}

static char *GetPath(size_t size)
{
    char *path = NULL;
    ssize_t len;

    path = (char *)malloc(size);
    if (path == NULL)
    {
        perror("Erro ao alocar memória");
        return NULL;
    }

    len = (ssize_t)getcwd(path, size);

    if (len == -1)
    {
        perror("Erro ao obter o diretório atual");
        free(path);
        return NULL;
    }

    if (len == (ssize_t)(size - 1))
    {
        free(path);
        return GetPath(size * 2);
    }

    return path;
}