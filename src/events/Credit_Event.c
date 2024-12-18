#include <Credit_Event.h>
#include <Credits_Scene.h>

static void Credit_Change_Text(Scene *scene);

void Credit_Event_OnClick_Close(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->layerCurrent = 1;
    Credit_Hide(manager->sceneManager->current);
}

void Credit_Wheel_Event(GameManager *manager, Object *this)
{
    (void)this;
    SDL_Event *event = manager->sceneManager->event;
    switch (event->type)
    {
    case SDL_MOUSEWHEEL:
        if (event->wheel.y > 0 || event->wheel.y < 0)
        {
            Credit_Change_Text(manager->sceneManager->current);
        }
        break;
    }
}

static void Credit_Change_Text(Scene *scene)
{
    int i = 0;
    char tag[20];
    Object *obj = NULL;

    snprintf(tag, 20, "txt-%d", (int)i);

    while ((obj = Scene_FindTag(scene, tag)))
    {
        if (obj->opacity == 255)
        {
            snprintf(tag, 20, "txt-%d", (i + 1) == 5 ? 0 : (i + 1));
            Object *next = Scene_FindTag(scene, tag);
            next->opacity = 255;

            obj->opacity = 0;
            break;
        }
        i++;

        if (i == 5)
            i = 0;

        snprintf(tag, 20, "txt-%d", i);
    }
}