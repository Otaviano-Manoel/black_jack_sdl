#include <Setting_Scene_Event.h>
#include <Game_Manager.h>

void Setting_OnClick_Difficulty(GameManager *manager, Object *this)
{
    manager->gameConfig->Difficulty_Change(manager->gameConfig);
    this->text->SetText(manager->sceneManager->renderer, this->text, GameConfig_Difficulty_String(manager->gameConfig), (SDL_Color){0, 0, 0, 255});
}

void Setting_OnClick_Style(GameManager *manager, Object *this)
{
    manager->gameConfig->Style_Change(manager->gameConfig);
    this->text->SetText(manager->sceneManager->renderer, this->text, GameConfig_Style_String(manager->gameConfig), (SDL_Color){0, 0, 0, 255});
}

void Setting_OnClick_Quit(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->layerCurrent = 1;
    Setting_Hide(manager->sceneManager->current);
}