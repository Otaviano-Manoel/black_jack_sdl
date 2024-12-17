#include <Setting_Scene.h>
#include <Setting_Scene_Event.h>

static void Setting_SetVisible(Scene *scene, SDL_bool visible);

void Setting_Draw(GameManager *gameManager)
{
    Object *obj = NULL;

    // Obj
    obj = Obj_CreateWithImage(gameManager, "background_dark.bmp", "back", 2, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 128, SDL_TRUE, SDL_FALSE, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_CreateWithImage(gameManager, "background_setting.bmp", "back", 2, 450, 162, 450, 450, 255, SDL_TRUE, SDL_FALSE, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_CreateWithImage(gameManager, "card.bmp", "card", 2, 630, 485, 100, 100, 255, SDL_TRUE, SDL_FALSE, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_CreateWithImage(gameManager, "close.bmp", "close", 2, 866, 137, 50, 50, 255, SDL_TRUE, SDL_TRUE, Setting_OnClick_Quit);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_CreateWithText(gameManager, NULL, (SDL_Color){255, 255, 255, 255}, "Difficulty", "font/MontserratAlternates-Medium.ttf", "difficulty", 2, 26, 469, 192, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_CreateWithImage(gameManager, "b_background.bmp", "b_difficulty", 2, 605, 192, 215, 35, 255, SDL_TRUE, SDL_TRUE, Setting_OnClick_Difficulty);
    Obj_CreateWithText(gameManager, obj, (SDL_Color){0, 0, 0, 255}, GameConfig_Difficulty_String(gameManager->gameConfig), "font/MontserratAlternates-Medium.ttf", obj->tag, 2, 26, 45, 1, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_CreateWithText(gameManager, NULL, (SDL_Color){255, 255, 255, 255}, "Style", "font/MontserratAlternates-Medium.ttf", "style", 2, 26, 469, 252, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_CreateWithImage(gameManager, "b_background.bmp", "b_style", 2, 605, 252, 215, 35, 255, SDL_TRUE, SDL_TRUE, Setting_OnClick_Style);
    Obj_CreateWithText(gameManager, obj, (SDL_Color){0, 0, 0, 255}, GameConfig_Style_String(gameManager->gameConfig), "font/MontserratAlternates-Medium.ttf", obj->tag, 2, 26, 45, 1, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_CreateWithText(gameManager, NULL, (SDL_Color){255, 255, 255, 255}, "Name P1", "font/MontserratAlternates-Medium.ttf", "nameP1", 2, 26, 469, 312, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_CreateWithImage(gameManager, "b_background.bmp", "P1", 2, 605, 312, 275, 35, 255, SDL_TRUE, SDL_TRUE, Setting_OnClick_SetName_P1);
    Obj_CreateWithText(gameManager, obj, (SDL_Color){0, 0, 0, 255}, gameManager->gamePlay->player[0]->name, "font/MontserratAlternates-Medium.ttf", obj->tag, 2, 26, 5, 2, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_CreateWithText(gameManager, NULL, (SDL_Color){255, 255, 255, 255}, "Name P2", "font/MontserratAlternates-Medium.ttf", "nameP2", 2, 26, 469, 377, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_CreateWithImage(gameManager, "b_background.bmp", "P2", 2, 605, 377, 275, 35, 255, SDL_TRUE, SDL_TRUE, Setting_OnClick_SetName_P2);
    Obj_CreateWithText(gameManager, obj, (SDL_Color){0, 0, 0, 255}, gameManager->gamePlay->player[1]->name, "font/MontserratAlternates-Medium.ttf", obj->tag, 2, 26, 5, 2, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    obj = Obj_CreateWithText(gameManager, NULL, (SDL_Color){255, 255, 255, 255}, "FullScreen: Alt + Enter", "font/MontserratAlternates-Medium.ttf", "full", 2, 26, 469, 435, 0, 255);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    Setting_Hide(gameManager->sceneManager->current);
}

void Setting_UpdateNamePlayer(GameManager *this, Player *player, Object *obj)
{
    obj->text->SetText(this->sceneManager->renderer, obj->text, obj->text->color, player->name, 0);
}

void Setting_Visible(Scene *scene)
{
    Setting_SetVisible(scene, SDL_TRUE);
}

void Setting_Hide(Scene *scene)
{
    Setting_SetVisible(scene, SDL_FALSE);
}

static void Setting_SetVisible(Scene *scene, SDL_bool visible)
{
    for (size_t i = 0; i < scene->objCount; i++)
    {
        Object *obj = scene->objects[i];

        if (obj->layer == 2)
        {
            obj->isVisible = visible;
        }
    }
}