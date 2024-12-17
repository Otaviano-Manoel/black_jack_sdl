#include <Menu_Scene.h>
#include <Credits_Scene.h>

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
    Credit_Draw(manager);
}

static void Menu_Draw(GameManager *manager)
{
    manager->sceneManager->layerCurrent = 1;
    Object *obj = NULL;

    // Obj
    obj = Obj_CreateWithImage(manager, "background.bmp", "back", 0, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 255, SDL_TRUE, SDL_FALSE, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj
    obj = Obj_CreateWithImage(manager, "title.bmp", "title", 0, 86, 107, 460, 460, 255, SDL_TRUE, SDL_FALSE, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS CPU
    obj = Obj_CreateWithImage(manager, "button.bmp", "pvscpu", 1, 708, 113, 350, 90, 255, SDL_TRUE, SDL_TRUE, Menu_OnClick_PvsCPU);
    Obj_CreateWithText(manager, obj, (SDL_Color){0, 0, 0, 255}, "P vs CPU", "font/MontserratAlternates-ExtraBold.ttf", obj->tag, obj->layer, 32, 137, 25, 0, obj->opacity);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS P
    obj = Obj_CreateWithImage(manager, "button.bmp", "pvsp", 1, 708, 223, 350, 90, 255, SDL_TRUE, SDL_TRUE, Menu_OnClick_PvsP);
    Obj_CreateWithText(manager, obj, (SDL_Color){0, 0, 0, 255}, "P vs P", "font/MontserratAlternates-ExtraBold.ttf", obj->tag, obj->layer, 32, 137, 25, 0, obj->opacity);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj SETTINGS
    obj = Obj_CreateWithImage(manager, "button.bmp", "setting", 1, 708, 353, 350, 90, 255, SDL_TRUE, SDL_TRUE, Menu_OnClick_Settings);
    Obj_CreateWithText(manager, obj, (SDL_Color){0, 0, 0, 255}, "Settings", "font/MontserratAlternates-ExtraBold.ttf", obj->tag, obj->layer, 32, 137, 25, 0, obj->opacity);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj QUIT

    obj = Obj_CreateWithImage(manager, "button.bmp", "quit", 1, 708, 473, 350, 90, 255, SDL_TRUE, SDL_TRUE, Menu_OnClick_Quit);
    Obj_CreateWithText(manager, obj, (SDL_Color){0, 0, 0, 255}, "Quit", "font/MontserratAlternates-ExtraBold.ttf", obj->tag, obj->layer, 32, 137, 25, 0, obj->opacity);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    obj = Obj_CreateWithImage(manager, "credits.bmp", "credit", 1, 1160, 605, 120, 120, 255, SDL_TRUE, SDL_TRUE, Menu_OnClick_Credits);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);
}

static void Menu_Update(GameManager *manager)
{
    (void)manager;
}
static void Menu_Quit(GameManager *manager)
{
    Scene_Free(manager->sceneManager->current);
}