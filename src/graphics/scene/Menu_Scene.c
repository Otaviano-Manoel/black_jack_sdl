#include <Menu_Scene.h>

static void Menu_Start(GameManager *manager);
static void Menu_Update(GameManager *manager);
static void Menu_Quit(GameManager *manager);
static void Menu_Draw(GameManager *manager);

Scene *Menu_Scene_Init()
{
    Scene *scene = Scene_Init();
    scene->Start = Menu_Start;
    scene->Update = Menu_Update;
    scene->Quit = Menu_Quit;
    return scene;
}

static void Menu_Start(GameManager *manager)
{
    Menu_Draw(manager);
    Setting_Draw(manager);
}

static void Menu_Draw(GameManager *manager)
{
    manager->sceneManager->layerCurrent = 1;
    Object obj;
    SceneManager *sceneManager = manager->sceneManager;

    // Obj
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(manager->assets, "background.bmp"), 0, 0, 0, SDL_TRUE, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 86, 107, 460, 460, BuildFilePath(manager->assets, "title.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_FALSE, NULL, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS CPU
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 708, 113, 350, 90, BuildFilePath(manager->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_PvsCPU);
    obj.text->InitFull(sceneManager, &obj, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "P vs CPU", (SDL_Color){0, 0, 0, 255}, 137, 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS P
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 708, 233, 350, 90, BuildFilePath(manager->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_PvsP);
    obj.text->InitFull(sceneManager, &obj, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "P vs P", (SDL_Color){0, 0, 0, 255}, 137, 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj SETTINGS
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 708, 353, 350, 90, BuildFilePath(manager->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_Settings);
    obj.text->InitFull(sceneManager, &obj, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "Settings", (SDL_Color){0, 0, 0, 255}, 137, 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj QUIT
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 708, 473, 350, 90, BuildFilePath(manager->assets, "button.bmp"), 0, 0, 0, SDL_TRUE, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_Quit);
    obj.text->InitFull(sceneManager, &obj, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "Quit", (SDL_Color){0, 0, 0, 255}, 170, 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);
}

static void Menu_Update(GameManager *manager)
{
    (void)manager;
}
static void Menu_Quit(GameManager *manager)
{
    (void)manager;
}