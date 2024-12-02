#include <Setting.h>
#include <ObjectEvent.h>

void Setting_Init(GameManager *gameManager)
{
    gameManager->sceneManager->layerCurrent = 3;
    Object obj;
    SDL_Renderer *renderer = gameManager->sceneManager->renderer;

    // Obj
    obj = Obj_Init();
    obj.layer = 2;
    obj.opacity = 128;
    obj.ResizeRect(&obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "setting.bmp"), MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    RegisterEvent(&obj, NULL, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.layer = 2;
    obj.ResizeRect(&obj, 450, 162, 451, 397);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "background_setting.bmp"), 381, 397);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.layer = 2;
    obj.ResizeRect(&obj, 590, 450, 100, 100);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "card.bmp"), 100, 100);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 866, 137, 50, 50);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "close.bmp"), 50, 50);
    RegisterEvent(&obj, NULL, NULL);
    obj.isButton = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 469, 192, 0, 0);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "null.bmp"), 50, 50);
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, "Difficulty", (SDL_Color){255, 255, 255, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x), (obj.rect->y));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Difficulty
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 605, 192, 215, 35);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "b_background.bmp"), 215, 35);
    RegisterEvent(&obj, NULL, NULL);
    obj.isButton = SDL_TRUE;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, GameConfig_DifficultyString(gameManager->gameConfig), (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 45), (obj.rect->y + 1));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 469, 252, 0, 0);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "null.bmp"), 50, 50);
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, "Style", (SDL_Color){255, 255, 255, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x), (obj.rect->y));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Style
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 605, 252, 215, 35);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "b_background.bmp"), 215, 35);
    RegisterEvent(&obj, NULL, NULL);
    obj.isButton = SDL_TRUE;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, GameConfig_StyleString(gameManager->gameConfig), (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 45), (obj.rect->y + 1));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 469, 312, 0, 0);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "null.bmp"), 50, 50);
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, "Name P1", (SDL_Color){255, 255, 255, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x), (obj.rect->y));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P1
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 605, 312, 275, 35);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "b_background.bmp"), 215, 35);
    RegisterEvent(&obj, NULL, NULL);
    obj.isButton = SDL_TRUE;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 17);
    obj.text->SetColor(gameManager, obj.text, "14", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 5), (obj.rect->y + 5));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 469, 377, 0, 0);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "null.bmp"), 50, 50);
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 26);
    obj.text->SetColor(gameManager, obj.text, "Name P2", (SDL_Color){255, 255, 255, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x), (obj.rect->y));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);

    // Obj Name P2
    obj = Obj_Init();
    obj.layer = 3;
    obj.ResizeRect(&obj, 605, 377, 275, 35);
    obj.SetImage(renderer, &obj, BuildFilePath(gameManager->assets, "b_background.bmp"), 275, 35);
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(gameManager->assets, "font/MontserratAlternates-Medium.ttf"), 17);
    obj.text->SetColor(gameManager, obj.text, "14", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 5), (obj.rect->y + 5));
    obj.text->isTextLoaded = SDL_TRUE;
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);
}