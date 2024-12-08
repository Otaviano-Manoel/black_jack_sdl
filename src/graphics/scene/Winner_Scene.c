#include <Winner_Scene.h>

static void Winner_Scene_Start(GameManager *this);
static void Winner_Scene_Update(GameManager *this);
static void Winner_Scene_Quit(GameManager *this);
static char *Winner_TotalWinnerInString(Player *p);
static void Winner_LoadPlayerWinner(GameManager *this);
static void Winner_LoadPlayerLoser(GameManager *this);

Scene *Winner_Scene_Init()
{
    Scene *scene = Scene_Init();
    scene->Start = Winner_Scene_Start;
    scene->Update = Winner_Scene_Update;
    scene->Quit = Winner_Scene_Quit;
    return scene;
}

static void Winner_Scene_Start(GameManager *this)
{
    Winnar_OnInit(this);
    this->sceneManager->layerCurrent = 1;
    Object obj;
    SDL_Renderer *renderer = this->sceneManager->renderer;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "background.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Winner_LoadPlayerLoser(this);

    Winner_LoadPlayerWinner(this);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 245, 588, 331, 80, BuildFilePath(this->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Winner_OnPlayAgain);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Play Again", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 115, obj.rect->y + 22);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 753, 588, 331, 80, BuildFilePath(this->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Winner_OnMainMenu);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Black.ttf"), 26, "Main Menu", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 115, obj.rect->y + 22);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 280, 215, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, this->gamePlay->player[0]->name, (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 280, 295, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, Winner_TotalWinnerInString(this->gamePlay->player[0]), (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 790, 215, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, this->gamePlay->player[1]->name, (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 790, 295, 0, 0, BuildFilePath(this->assets, "null.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(this->assets, "font/MontserratAlternates-Bold.ttf"), 26, Winner_TotalWinnerInString(this->gamePlay->player[1]), (SDL_Color){255, 255, 255, 255}, (obj.rect->x), (obj.rect->y));
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Winner_Scene_Update(GameManager *this)
{
    (void)this;
}

static void Winner_Scene_Quit(GameManager *this)
{
    (void)this;
}

static void Winner_LoadPlayerWinner(GameManager *this)
{
    Object obj;
    SDL_Renderer *renderer = this->sceneManager->renderer;
    SDL_bool isP2 = GamePlay_GetWinner(this);

    int x;
    x = isP2 ? 769 : 261;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, x, 108, 300, 400, BuildFilePath(this->assets, "panel_win.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    x = isP2 ? 719 : 211;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, x, 361, 400, 266, BuildFilePath(this->assets, "star.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Winner_LoadPlayerLoser(GameManager *this)
{
    Object obj;
    SDL_Renderer *renderer = this->sceneManager->renderer;
    SDL_bool isP2 = GamePlay_GetWinner(this);

    int x;
    x = isP2 ? 261 : 769;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, x, 108, 300, 400, BuildFilePath(this->assets, "panel_lose.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static char *Winner_TotalWinnerInString(Player *p)
{
    char *buffer = SDL_malloc(sizeof(char) * 50);
    snprintf(buffer, 50, "Winners: %d", (int)p->totalWinner);
    return buffer;
}