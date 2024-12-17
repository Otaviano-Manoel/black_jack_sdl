#include <Object_Event.h>

static void ObjectEvent_OnHover(GameManager *manager, Object *this);
static void ObjectEvent_OnExit(GameManager *manager, Object *this);
static void ObjectEvent_OnAnimClick(GameManager *manager, Object *this);
static void ObjectEvent_UpdateAnimClick(GameManager *manager, Object *this);

void RegisterEvent(Object *this)
{
    this->OnHover = ObjectEvent_OnHover;
    this->OnLeave = ObjectEvent_OnExit;
    this->OnAnimClick = ObjectEvent_OnAnimClick;
}

static void ObjectEvent_OnHover(GameManager *manager, Object *this)
{
    (void)manager;
    this->opacity = 178;
}

static void ObjectEvent_OnExit(GameManager *manager, Object *this)
{
    (void)manager;
    this->opacity = 255;
}

static void ObjectEvent_OnAnimClick(GameManager *manager, Object *this)
{
    (void)manager;
    if (this->opacity < 255)
    {
        this->opacity = 255;
        ObjectEvent_UpdateAnimClick(manager, this);
    }

    SDL_Delay(100);

    if (this->opacity == 255)
    {
        this->opacity = 178;
        ObjectEvent_UpdateAnimClick(manager, this);
    }
}

static void ObjectEvent_UpdateAnimClick(GameManager *manager, Object *this)
{
    RenderObject(manager->sceneManager->renderer, this);
    PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window->window);
}
