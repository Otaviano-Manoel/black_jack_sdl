#include <Game_Manager.h>
#include <Menu_Scene.h>
#include <time.h>

int main()
{
    Uint32 frameTime;
    Uint32 frameStart;
    GameManager *gameManager = GameManager_Init();
    gameManager->sceneManager->ChangeScene(gameManager, Menu_Scene_Init());
    srand((unsigned int)time(NULL));

    while (!gameManager->quit)
    {
        frameStart = SDL_GetTicks();
        gameManager->sceneManager->Update(gameManager);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_TIME)
        {
            SDL_Delay(FRAME_TIME - frameTime);
        }
    }

    Game_Manager_Free(gameManager);
    SDL_Quit();

    return 0;
}

/*
void (*InitFull)(SceneManager *sceneManager, struct Object *obj,
                     int x, int y, int width, int height, const char *file,
                     SDL_bool isSetColor, Uint8 opacity, int layer, SDL_bool isButton,
                     void (*OnHover)(GameManager *manager, struct Object *this),
                     void (*OnExit)(GameManager *manager, struct Object *this),
                     void (*OnClick)(GameManager *manager, struct Object *this));
*/