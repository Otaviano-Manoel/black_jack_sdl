#include <Window_Change_Screen.h>

void Window_Change_Screen_OnFullScreen(SceneManager *sceneManager)
{
    if (sceneManager->window->isFullScreen)
    {
        SDL_SetWindowFullscreen(sceneManager->window->window, SDL_FALSE);
        sceneManager->window->isFullScreen = SDL_FALSE;
        sceneManager->window->UpdateScreen(sceneManager->window);
    }
    else
    {
        SDL_SetWindowFullscreen(sceneManager->window->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        sceneManager->window->isFullScreen = SDL_TRUE;
        sceneManager->window->UpdateScreen(sceneManager->window);
    }
    UpdateObjectScale(sceneManager);
}
