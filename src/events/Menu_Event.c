#include <Menu_Event.h>
#include <Setting_Scene.h>
#include <Game_Scene.h>

void Menu_OnClick_PvsCPU(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->ChangeScene(manager, Game_Scene_Init());
}

void Menu_OnClick_PvsP(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;
}

void Menu_OnClick_Settings(GameManager *manager, Object *this)
{
    (void)this;

    manager->sceneManager->layerCurrent = 2;
    Setting_Visible(manager->sceneManager->current);
}

void Menu_OnClick_Quit(GameManager *manager, Object *this)
{
    (void)this;

    manager->quit = SDL_TRUE;
}