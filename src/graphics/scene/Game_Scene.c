#include <Game_Scene.h>
#include <Game_Event.h>

static void Game_Scene_Start(GameManager *this);
static void Game_Scene_Update(GameManager *this);
static void Game_Scene_Quit(GameManager *this);

Scene *Game_Scene_Init()
{
    Scene *scene = Scene_Init();
    scene->Start = Game_Scene_Start;
    scene->Update = Game_Scene_Update;
    scene->Quit = Game_Scene_Quit;
    return scene;
}

static void Game_Scene_Start(GameManager *this)
{
    this->sceneManager->layerCurrent = 1;
    Object obj;
    SDL_Renderer *renderer = this->sceneManager->renderer;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "background.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 324, 30, 660, 660, BuildFilePath(this->assets, "title.bmp"), 0, 0, 0, SDL_TRUE, 25, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 1053, 137, 120, 160, BuildFilePath(this->assets, "cards/back_grey.bmp"), 0, 0, 0, SDL_FALSE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.SetTag(&obj, "deck");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 66, 39, 120, 160, BuildFilePath(this->assets, "cards/back_blue.bmp"), 0, 0, 0, SDL_FALSE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.SetTag(&obj, "c-p1");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 66, 241, 120, 160, BuildFilePath(this->assets, "cards/back_red.bmp"), 0, 0, 0, SDL_FALSE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.SetTag(&obj, "c-p2");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    // p1

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 180, 542, 200, 70, BuildFilePath(this->assets, "button_small_red.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Game_OnHit_P1);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Hit", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 100, obj.rect->y + 19);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 408, 542, 200, 70, BuildFilePath(this->assets, "button_small_red.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Stand", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 90, obj.rect->y + 17);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 280, 628, 200, 70, BuildFilePath(this->assets, "button_small_red.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Exit", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 90, obj.rect->y + 17);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 200, 450, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, this->gamePlay->player[0]->name, (SDL_Color){255, 255, 255, 255}, obj.rect->x, obj.rect->y);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 200, 495, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, "Pontos: 00", (SDL_Color){255, 255, 255, 255}, obj.rect->x, obj.rect->y);
    obj.SetTag(&obj, "p-p1");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    // p2

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 700, 542, 200, 70, BuildFilePath(this->assets, "button_small_blue.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Game_OnHit_P2);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Hit", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 100, obj.rect->y + 19);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 928, 542, 200, 70, BuildFilePath(this->assets, "button_small_blue.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Stand", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 90, obj.rect->y + 17);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 800, 628, 200, 70, BuildFilePath(this->assets, "button_small_blue.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Exit", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 90, obj.rect->y + 17);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 720, 450, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, this->gamePlay->player[1]->name, (SDL_Color){255, 255, 255, 255}, obj.rect->x, obj.rect->y);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 720, 495, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, "Pontos: 00", (SDL_Color){255, 255, 255, 255}, obj.rect->x, obj.rect->y);
    obj.SetTag(&obj, "p-p2");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Game_Scene_Update(GameManager *this)
{
    (void)this;
}

static void Game_Scene_Quit(GameManager *this)
{
    (void)this;
}