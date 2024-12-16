#include <Credits_Scene.h>
#include <Credit_Event.h>

static void Credit_SetVisible(Scene *scene, SDL_bool visible);
static char *Author()
{
    return "Criado por: \n - Otaviano Manoel \n GitHub: \n - Repositorio: [Black Jack SDL] \n (https://github.com/Otaviano-Manoel/black_jack_sdl)";
}

void Credit_Visible(Scene *scene)
{
    Credit_SetVisible(scene, SDL_TRUE);
}

void Credit_Hide(Scene *scene)
{
    Credit_SetVisible(scene, SDL_FALSE);
}

static void Credit_SetVisible(Scene *scene, SDL_bool visible)
{
    for (size_t i = 0; i < scene->objCount; i++)
    {
        Object *obj = &scene->objects[i];

        if (obj->layer == 5)
        {
            obj->isVisible = visible;
        }
    }
}

void Credit_Draw(GameManager *this)
{
    Object obj;
    SceneManager *sceneManager = this->sceneManager;

    // Obj
    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "setting.bmp"), SDL_TRUE, 128, 5, SDL_FALSE, NULL, NULL, NULL);
    obj.SetTag(&obj, "credit");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 174, 0, 933, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "setting.bmp"), SDL_TRUE, 255, 5, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 1050, 20, 40, 40, BuildFilePath(this->assets, "close.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, Credit_Event_OnClick_Close);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 543, 20, 160, 160, BuildFilePath(this->assets, "gifs/banners/f5376484900944eabc667d5540289309l7qesnaO9ufsR6PC-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-0");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/banners"), 35, 2, "f5376484900944eabc667d5540289309l7qesnaO9ufsR6PC-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 200, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-1");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 320, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-2");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 440, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-3");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 560, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-4");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 680, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-5");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 800, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-6");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 920, 570, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-7");
    Gif_Init(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, 1, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 469, 192, 0, 0, BuildFilePath(this->assets, "null.bmp"), SDL_TRUE, 255, 5, SDL_FALSE, NULL, NULL, NULL);
    obj.text->InitFull(sceneManager, &obj, obj.text, BuildFilePath(this->assets, "Inter/Inter_24pt-Medium.ttf"), 26, Author(), (SDL_Color){255, 255, 255, 255}, 0, 0);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Credit_Hide(this->sceneManager->current);
}

void Credit_RunAnim(GameManager *this)
{
    Scene *credit = this->sceneManager->current;

    for (size_t i = 0; i < 8; i++)
    {
        char tag[20];
        snprintf(tag, 20, "anim-%d", (int)i);
        Object *obj = Scene_FindTag(credit, tag);
        if (obj != NULL)
        {
            Gif_UpdateFrame(this->sceneManager->renderer, obj);
        }
    }
}