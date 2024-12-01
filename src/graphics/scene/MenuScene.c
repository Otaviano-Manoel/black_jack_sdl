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
    obj.layer = 0;
    obj.Obj_ResizeRect(&obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "background.bmp"), MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    SDL_strlcpy(obj.tag, TAG_BACKGROUND, sizeof(obj.tag));
    RegisterEvent(&obj, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj
    obj = Obj_Init();
    obj.layer = 1;
    obj.Obj_ResizeRect(&obj, 86, 107, 460, 460);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "title.bmp"), 460, 460);
    RegisterEvent(&obj, NULL, NULL);
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS CPU
    obj = Obj_Init();
    obj.layer = 1;
    RegisterEvent(&obj, NULL, NULL);
    obj.Obj_ResizeRect(&obj, 708, 113, 350, 90);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "menu/button.bmp"), 350, 90);
    obj.isButton = SDL_TRUE;
    obj.OnClick = Menu_OnClick_PvsCPU;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32);
    obj.text->SetColor(manager, obj.text, "P vs CPU", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 137), (obj.rect->y + 25));
    obj.text->isTextLoaded = SDL_TRUE;
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj P VS P
    obj = Obj_Init();
    obj.layer = 1;
    RegisterEvent(&obj, NULL, NULL);
    obj.Obj_ResizeRect(&obj, 708, 233, 350, 90);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "menu/button.bmp"), 350, 90);
    obj.isButton = SDL_TRUE;
    obj.OnClick = Menu_OnClick_PvsP;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32);
    obj.text->SetColor(manager, obj.text, "P vs P", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 137), (obj.rect->y + 25));
    obj.text->isTextLoaded = SDL_TRUE;
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj SETTINGS
    obj = Obj_Init();
    obj.layer = 1;
    RegisterEvent(&obj, NULL, NULL);
    obj.Obj_ResizeRect(&obj, 708, 353, 350, 90);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "menu/button.bmp"), 350, 90);
    obj.isButton = SDL_TRUE;
    obj.OnClick = Menu_OnClick_Settings;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32);
    obj.text->SetColor(manager, obj.text, "Settings", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 137), (obj.rect->y + 25));
    obj.text->isTextLoaded = SDL_TRUE;
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);

    // Obj QUIT
    obj = Obj_Init();
    obj.layer = 1;
    RegisterEvent(&obj, NULL, NULL);
    obj.Obj_ResizeRect(&obj, 708, 473, 350, 90);
    obj.Obj_SetImage(renderer, &obj, BuildFilePath(manager->assets, "menu/button.bmp"), 350, 90);
    obj.isButton = SDL_TRUE;
    obj.OnClick = Menu_OnClick_Quit;
    // Text
    obj.text->SetFont(obj.text, BuildFilePath(manager->assets, "font/MontserratAlternates-ExtraBold.ttf"), 32);
    obj.text->SetColor(manager, obj.text, "Quit", (SDL_Color){0, 0, 0, 255});
    obj.text->SetPosition(obj.text, (obj.rect->x + 137), (obj.rect->y + 25));
    obj.text->isTextLoaded = SDL_TRUE;
    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj);
}

static void Menu_Update(GameManager *manager)
{
    for (size_t i = 0; i < manager->sceneManager->current->objCount; i++)
    {
        Object *element = &manager->sceneManager->current->objects[i];
        SDL_SetTextureAlphaMod(element->texture, element->opacity);

        SDL_RenderCopy(manager->sceneManager->renderer, element->texture, NULL, element->rect);

        if (element->text->isTextLoaded)
        {
            SDL_SetTextureAlphaMod(element->text->textTexture, element->opacity);
            SDL_RenderCopy(manager->sceneManager->renderer, element->text->textTexture, NULL, element->text->textRect);
        }
    }
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