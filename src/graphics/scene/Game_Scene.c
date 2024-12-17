#include <Game_Scene.h>
#include <Game_Event.h>
#include <CPU.h>
#include <Rules.h>

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
    Object *obj;

    obj = Obj_CreateWithImage(this, "background.bmp", "background", 0, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "title.bmp", "title", 0, 324, 30, 660, 660, 25, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "cards/back_grey.bmp", "deck", 0, 1053, 137, 120, 160, 255, SDL_FALSE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "cards/back_blue.bmp", "c-p1", 0, 66, 39, 120, 160, 255, SDL_FALSE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "cards/back_red.bmp", "c-p2", 0, 66, 241, 120, 160, 255, SDL_FALSE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, "TURN", "font/MontserratAlternates-Black.ttf", "turn", 0, 26, 1060, 30, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, this->gamePlay->player[0]->name, "font/MontserratAlternates-Bold.ttf", "turn-name", 0, 20, 1000, 70, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    // p1

    obj = Obj_CreateWithImage(this, "button_small_red.bmp", "hitp1", 1, 180, 542, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnHit_P1);
    Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Hit", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 100, 19, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "button_small_red.bmp", "standp1", 1, 408, 542, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnStand_P1);
    Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Stand", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 90, 17, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "button_small_red.bmp", "exitp1", 1, 280, 628, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnExit);
    Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Exit", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 90, 17, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, this->gamePlay->player[0]->name, "font/MontserratAlternates-Bold.ttf", "namep1", 0, 26, 200, 450, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, "Points: 00", "font/MontserratAlternates-Bold.ttf", "p-p1", 0, 26, 200, 495, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    // p2

    if (this->gamePlay->player[1]->isPlayer)
    {

        obj = Obj_CreateWithImage(this, "button_small_blue.bmp", "hitp2", 1, 700, 542, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnHit_P2);
        Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Hit", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 100, 19, 0, 255);
        this->sceneManager->current->AddObj(this->sceneManager->current, obj);

        obj = Obj_CreateWithImage(this, "button_small_blue.bmp", "standp2", 1, 928, 542, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnStand_P2);
        Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Stand", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 90, 17, 0, 255);
        this->sceneManager->current->AddObj(this->sceneManager->current, obj);

        obj = Obj_CreateWithImage(this, "button_small_blue.bmp", "exitp2", 1, 800, 628, 200, 70, 255, SDL_TRUE, SDL_TRUE, Game_OnExit);
        Obj_CreateWithText(this, obj, (SDL_Color){0, 0, 0, 255}, "Exit", "font/MontserratAlternates-Black.ttf", obj->tag, obj->layer, 26, 90, 17, 0, 255);
        this->sceneManager->current->AddObj(this->sceneManager->current, obj);
    }

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, this->gamePlay->player[1]->name, "font/MontserratAlternates-Bold.ttf", "namep2", 0, 26, 720, 450, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, "Points: 00", "font/MontserratAlternates-Bold.ttf", "p-p2", 0, 26, 720, 495, 0, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Game_Scene_Update(GameManager *this)
{
    if (Rule_ValidateVictory(this) || Rule_ValidateLoser(this))
    {
        this->sceneManager->ChangeScene(this, Winner_Scene_Init());
        return;
    }

    if (!this->gamePlay->player[1]->isPlayer && this->gamePlay->turn == 1)
    {
        // funçao da CPU
        if (Cpu_IsHit(this))
            Game_OnHit_P2(this, NULL);
        else if (Cpu_IsStand(this))
            Game_OnStand_P2(this, NULL);
    }
}

static void Game_Scene_Quit(GameManager *this)
{
    Scene_Free(this->sceneManager->current);
}