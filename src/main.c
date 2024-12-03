#include <Game_Manager.h>
#include <Menu_Scene.h>

int main()
{
    Uint32 frameTime;
    Uint32 frameStart;
    GameManager *gameManager = GameManager_Init();
    gameManager->sceneManager->ChangeScene(gameManager, Menu_Init());

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