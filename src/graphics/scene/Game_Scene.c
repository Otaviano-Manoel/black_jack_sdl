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
    obj.InitFull(renderer, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "background.bmp"), 0, 0, 0, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 324, 30, 660, 660, BuildFilePath(this->assets, "title.bmp"), 0, 0, 0, 25, 0, SDL_FALSE, NULL, NULL, NULL);
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