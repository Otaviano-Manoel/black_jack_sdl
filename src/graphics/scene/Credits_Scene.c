#include <Credits_Scene.h>
#include <Credit_Event.h>

static void Credit_SetVisible(Scene *scene, SDL_bool visible);
/*static char *Author()
{
    return "Criado por: \n - Otaviano Manoel \n GitHub: \n - Repositorio: [Black Jack SDL] \n (https://github.com/Otaviano-Manoel/black_jack_sdl)";
}*/

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
        Object *obj = scene->objects[i];

        if (obj->layer == 5)
        {
            obj->isVisible = visible;
        }
    }
}

void Credit_Draw(GameManager *this)
{
    Object *obj = NULL;

    // Obj
    obj = Obj_CreateWithImage(this, "background_dark.bmp", "creditback", 5, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 128, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "background_dark.bmp", "creditbackdark", 5, 174, 0, 933, MAX_HEIGHT_WINDOW, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "close.bmp", "creditclose", 5, 1050, 20, 40, 40, 255, SDL_TRUE, SDL_TRUE, Credit_Event_OnClick_Close);
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