#include <Winner_Scene.h>

static void Winner_Scene_Start(GameManager *this);
static void Winner_Scene_Update(GameManager *this);
static void Winner_Scene_Quit(GameManager *this);
static void Winner_DrawPanel(GameManager *this);
static void Winner_LoadPlayerDraw(GameManager *this);
static void Winner_LoadPlayerWinner(GameManager *this);
static void Winner_LoadPlayerLoser(GameManager *this);
static void Winner_Panel(GameManager *this, SDL_bool isP2, char *panelBMP);
static char *Winner_TotalWinnerInString(Player *p);

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
    Winner_OnInit(this);
    this->sceneManager->layerCurrent = 1;
    Object *obj = NULL;

    obj = Obj_CreateWithImage(this, "background.bmp", "background", 0, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 255, SDL_FALSE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Winner_DrawPanel(this);

    obj = Obj_CreateWithImage(this, "button.bmp", "play-again", 1, 245, 588, 331, 80, 255, SDL_TRUE, SDL_TRUE, Winner_OnPlayAgain);
    Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Play Again", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 115, 22, 0, obj->opacity);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "button.bmp", "main-menu", 1, 753, 588, 331, 80, 255, SDL_TRUE, SDL_TRUE, Winner_OnMainMenu);
    Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Main Menu", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 115, 22, 0, obj->opacity);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, this->gamePlay->player[0]->name, "font/MontserratAlternates-Bold.ttf", "nameP1", 1, 26, 280, 215, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Winner_TotalWinnerInString(this->gamePlay->player[0]), "font/MontserratAlternates-Bold.ttf", "winnerP1", 1, 26, 280, 295, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, this->gamePlay->player[1]->name, "font/MontserratAlternates-Bold.ttf", "nameP2", 1, 26, 790, 215, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Winner_TotalWinnerInString(this->gamePlay->player[1]), "font/MontserratAlternates-Bold.ttf", "winnerP2", 1, 26, 790, 295, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Winner_Scene_Update(GameManager *this)
{
    (void)this;
}

static void Winner_Scene_Quit(GameManager *this)
{
    Scene_Free(this->sceneManager->current);
}

static void Winner_DrawPanel(GameManager *this)
{
    Player *p1 = this->gamePlay->player[0];
    Player *p2 = this->gamePlay->player[1];

    if (p1->isWinner && p2->isWinner)
    {
        Winner_LoadPlayerDraw(this);
    }
    else
    {
        Winner_LoadPlayerWinner(this);
        Winner_LoadPlayerLoser(this);
    }
}

static void Winner_LoadPlayerDraw(GameManager *this)
{
    Winner_Panel(this, SDL_TRUE, "panel_draw.bmp");
    Winner_Panel(this, SDL_FALSE, "panel_draw.bmp");
}

static void Winner_LoadPlayerWinner(GameManager *this)
{
    Player *p = GamePlay_GetWinner(this);

    Winner_Panel(this, p->isP1, "panel_win.bmp");

    int x = p->isP1 ? 211 : 719;

    Object *obj = Obj_CreateWithImage(this, "star.bmp", "star", 1, x, 361, 400, 266, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Winner_LoadPlayerLoser(GameManager *this)
{
    Player *p = GamePlay_GetWinner(this);
    Winner_Panel(this, !p->isP1, "panel_lose.bmp");
}

static void Winner_Panel(GameManager *this, SDL_bool isP1, char *panelBMP)
{
    int x = isP1 ? 261 : 769;

    Object *obj = Obj_CreateWithImage(this, panelBMP, "panel", 1, x, 108, 300, 400, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static char *Winner_TotalWinnerInString(Player *p)
{
    char *buffer = SDL_malloc(sizeof(char) * 50);
    snprintf(buffer, 50, "Winners: %d", (int)p->totalWinner);
    return buffer;
}