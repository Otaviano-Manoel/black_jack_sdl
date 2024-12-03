#include <Game_Scene.h>

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
    (void)obj;
    (void)renderer;

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 708, 473, 350, 90, BuildFilePath(this->assets, "menu/button.bmp"), 0, 0, 0, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_Quit);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);
}

static void Game_Scene_Update(GameManager *this)
{
    (void)this;
}

static void Game_Scene_Quit(GameManager *this)
{
    Scene_Free(this->sceneManager->current);
    SDL_free(this->sceneManager->current);
}