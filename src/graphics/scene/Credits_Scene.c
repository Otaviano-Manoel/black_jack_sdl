#include <Credits_Scene.h>
#include <Credit_Event.h>

static void Credit_SetVisible(Scene *scene, SDL_bool visible);

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
    obj.InitFull(sceneManager, &obj, 600, 20, 160, 160, BuildFilePath(this->assets, "gifs/naipes/f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-0");
    Create_Gif(&obj, BuildFilePath(this->assets, "gifs/naipes"), 116, "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 600, 200, 160, 160, BuildFilePath(this->assets, "gifs/innovation/3ffba34cc1074ec4dfa59a54ab52d93bH6RNeBAHFMLOV0wS-0.bmp"), SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, NULL);
    obj.SetTag(&obj, "anim-1");
    Create_Gif(&obj, BuildFilePath(this->assets, "gifs/innovation"), 45, "3ffba34cc1074ec4dfa59a54ab52d93bH6RNeBAHFMLOV0wS-");
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Credit_Hide(this->sceneManager->current);
}

void Credit_RunAnim(GameManager *this)
{
    Scene *credit = this->sceneManager->current;

    for (size_t i = 0; i < 2; i++)
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