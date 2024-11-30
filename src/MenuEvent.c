#include <MenuEvent.h>
#include <Setting.h>

void Menu_OnClick_PvsCPU(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;
}

void Menu_OnClick_PvsP(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;
}

void Menu_OnClick_Settings(GameManager *manager, Object *this)
{
    (void)this;

    Setting_Init(manager);
}

void Menu_OnClick_Quit(GameManager *manager, Object *this)
{
    (void)this;

    manager->quit = SDL_TRUE;
}