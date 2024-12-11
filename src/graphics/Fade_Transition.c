#include <Fade_Transition.h>

static void Fade_Change_Scene(GameManager *manager, Scene *next);

void Fade_Transition(GameManager *manager, Scene *next)
{

    manager->sceneManager->layerCurrent = 10;
    Object fade;

    fade = Obj_Init();
    fade.InitFull(manager->sceneManager->renderer, &fade, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW,
                  BuildFilePath(manager->assets, "setting.bmp"), 255, 255, 255,
                  SDL_TRUE, 0, 5, SDL_FALSE, NULL, NULL, NULL);

    Uint8 opacityStep = 5;

    while (fade.opacity < 255)
    {
        ClearRender(manager->sceneManager->renderer);
        if (manager->sceneManager->isCurrentSet)
            RenderObjectsInScene(manager);
        RenderObject(manager->sceneManager->renderer, &fade);
        PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window->window);

        fade.opacity += opacityStep;

        SDL_Delay(8);
    }

    Fade_Change_Scene(manager, next);

    while (fade.opacity > 0)
    {
        ClearRender(manager->sceneManager->renderer);
        if (manager->sceneManager->isCurrentSet)
            RenderObjectsInScene(manager);
        RenderObject(manager->sceneManager->renderer, &fade);
        PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window->window);

        fade.opacity -= opacityStep;

        SDL_Delay(8);
    }

    Obj_Free(&fade);
    manager->sceneManager->layerCurrent = 1;
}

static void Fade_Change_Scene(GameManager *manager, Scene *next)
{
    if (manager->sceneManager->isCurrentSet)
    {
        manager->sceneManager->Quit(manager);
        manager->sceneManager->current = NULL;
    }

    manager->sceneManager->current = next;
    manager->sceneManager->isCurrentSet = SDL_TRUE;
    manager->sceneManager->Start(manager);
}