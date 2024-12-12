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
    obj.InitFull(sceneManager, &obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "setting.bmp"), 0, 0, 0, SDL_TRUE, 128, 5, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 174, 0, 933, MAX_HEIGHT_WINDOW, BuildFilePath(this->assets, "setting.bmp"), 0, 0, 0, SDL_TRUE, 255, 5, SDL_FALSE, NULL, NULL, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_Init();
    obj.InitFull(sceneManager, &obj, 1050, 20, 40, 40, BuildFilePath(this->assets, "close.bmp"), 0, 0, 0, SDL_TRUE, 255, 5, SDL_TRUE, NULL, NULL, Credit_Event_OnClick_Close);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Credit_Hide(this->sceneManager->current);
}