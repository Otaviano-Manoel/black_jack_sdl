#include <MenuScene.h>

static void Menu_Start(GameManager *manager);
static void Menu_Update(GameManager *manager);
static void Menu_Quit(GameManager *manager);

Scene *Menu_Init()
{
    Scene *scene = Scene_Init();
    scene->Start = Menu_Start;
    scene->Update = Menu_Update;
    scene->Quit = Menu_Quit;
    return scene;
}

static void Menu_Start(GameManager *manager)
{
    manager->sceneManager->layerCurrent = 1;
    Object obj;
    SDL_Renderer *renderer = manager->sceneManager->renderer;

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(manager->assets, "background.bmp"), 0, 0, 0, 255, 0, SDL_FALSE, NULL, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 86, 107, 460, 460, BuildFilePath(manager->assets, "title.bmp"), 0, 0, 0, 255, 1, SDL_FALSE, NULL, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS CPU
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 708, 113, 350, 90, BuildFilePath(manager->assets, "menu/button.bmp"), 0, 0, 0, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_PvsCPU);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "P vs CPU", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 137, obj.rect->y + 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS P
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 708, 233, 350, 90, BuildFilePath(manager->assets, "menu/button.bmp"), 0, 0, 0, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_PvsP);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "P vs P", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 137, obj.rect->y + 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj SETTINGS
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 708, 353, 350, 90, BuildFilePath(manager->assets, "menu/button.bmp"), 0, 0, 0, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_Settings);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "Settings", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 137, obj.rect->y + 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj QUIT
    obj = Obj_Init();
    obj.InitFull(renderer, &obj, 708, 473, 350, 90, BuildFilePath(manager->assets, "menu/button.bmp"), 0, 0, 0, 255, 1, SDL_TRUE, NULL, NULL, Menu_OnClick_Quit);
    obj.text->InitFull(renderer, obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32, "Quit", (SDL_Color){0, 0, 0, 255}, obj.rect->x + 170, obj.rect->y + 25);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);
}

static void Menu_Update(GameManager *manager)
{
    (void)manager;
}
static void Menu_Quit(GameManager *manager)
{
    for (size_t i = 0; i < manager->sceneManager->current->objCount; i++)
    {
        Object *obj = &manager->sceneManager->current->objects[i];
        SDL_FreeSurface(obj->surface);
        obj->surface = NULL;

        SDL_DestroyTexture(obj->texture);
        obj->texture = NULL;
    }

    free(manager->sceneManager->current->objects);
}