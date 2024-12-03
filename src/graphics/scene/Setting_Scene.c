#include <Setting_Scene.h>
#include <Setting_Scene_Event.h>

static void Setting_SetVisible(Scene *scene, SDL_bool visible);

void Setting_Draw(GameManager *gameManager)
{
    Object obj;
    SDL_Renderer *renderer = gameManager->sceneManager->renderer;

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(gameManager->assets, "setting.bmp"), 0, 0, 0, 128, 2, SDL_FALSE, NULL, NULL, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 450, 162, 451, 397, BuildFilePath(gameManager->assets, "background_setting.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 630, 450, 100, 100, BuildFilePath(gameManager->assets, "card.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 866, 137, 50, 50, BuildFilePath(gameManager->assets, "close.bmp"), 0, 0, 0, 255, 2, SDL_TRUE, NULL, NULL, Setting_OnClick_Quit);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 469, 192, 0, 0, BuildFilePath(gameManager->assets, "null.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, "Difficulty", (SDL_Color){255, 255, 255, 255}, obj.rect->x, obj.rect->y);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 605, 192, 215, 36, BuildFilePath(gameManager->assets, "b_background.bmp"), 0, 0, 0, 255, 2, SDL_TRUE, NULL, NULL, Setting_OnClick_Difficulty);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, GameConfig_Difficulty_String(gameManager->gameConfig), (SDL_Color){0, 0, 0, 255}, (obj.rect->x + 45), (obj.rect->y + 1));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 469, 252, 0, 0, BuildFilePath(gameManager->assets, "null.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, "Style", (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 605, 252, 215, 35, BuildFilePath(gameManager->assets, "b_background.bmp"), 0, 0, 0, 255, 2, SDL_TRUE, NULL, NULL, Setting_OnClick_Style);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, GameConfig_Style_String(gameManager->gameConfig), (SDL_Color){0, 0, 0, 255}, (obj.rect->x + 45), (obj.rect->y + 1));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 469, 312, 0, 0, BuildFilePath(gameManager->assets, "null.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, "Name P1", (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 605, 312, 275, 35, BuildFilePath(gameManager->assets, "b_background.bmp"), 0, 0, 0, 255, 2, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, gameManager->player[0]->name, (SDL_Color){0, 0, 0, 255}, (obj.rect->x + 5), (obj.rect->y + 2));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 469, 377, 0, 0, BuildFilePath(gameManager->assets, "null.bmp"), 0, 0, 0, 255, 2, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, "Name P2", (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 605, 377, 275, 35, BuildFilePath(gameManager->assets, "b_background.bmp"), 0, 0, 0, 255, 2, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26, gameManager->player[1]->name, (SDL_Color){0, 0, 0, 255}, (obj.rect->x + 5), (obj.rect->y + 2));
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    Setting_Hide(gameManager->sceneManager->current);
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
        Object *obj = &scene->objects[i];

        if (obj->layer == 2)
        {
            obj->isVisible = visible;
        }
    }
}