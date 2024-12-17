#include <Setting_Scene_Event.h>
#include <Text_Input_Event.h>
#include <Game_Manager.h>

void Setting_OnClick_Difficulty(GameManager *manager, Object *this)
{
    manager->gameConfig->Difficulty_Change(manager->gameConfig);
    this->text->SetText(manager->sceneManager->renderer, this->text, this->text->color, GameConfig_Difficulty_String(manager->gameConfig), 0);
}

void Setting_OnClick_Style(GameManager *manager, Object *this)
{
    manager->gameConfig->Style_Change(manager->gameConfig);
    this->text->SetText(manager->sceneManager->renderer, this->text, this->text->color, GameConfig_Style_String(manager->gameConfig), 0);
}

void Setting_OnClick_Quit(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->layerCurrent = 1;
    Setting_Hide(manager->sceneManager->current);
}

void Setting_OnClick_SetName_P1(GameManager *manager, Object *this)
{
    (void)this;
    manager->isEnableTextInput = SDL_TRUE;
    manager->gamePlay->player[0]->isEditName = SDL_TRUE;
}

void Setting_OnClick_SetName_P2(GameManager *manager, Object *this)
{
    (void)this;
    manager->isEnableTextInput = SDL_TRUE;
    manager->gamePlay->player[1]->isEditName = SDL_TRUE;
}