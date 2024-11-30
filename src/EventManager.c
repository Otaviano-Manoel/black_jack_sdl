#include <EventManager.h>

static void Event_GetMouseHover(GameManager *this);

void Event_Wait(GameManager *this)
{
    SDL_Event *event = this->sceneManager->event;
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            this->quit = SDL_TRUE; // Set quit flag to true
        }
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            int index = SceneManager_GetObjisHover(this);

            if (index != -1)
            {
                Object *obj = &this->sceneManager->current->objects[index];
                obj->OnAnimClick(this, obj);
                obj->OnClick(this, obj);
            }
        }
        if (event->type == SDL_MOUSEMOTION)
        {
            Event_GetMouseHover(this);
        }
    }
}

static void Event_GetMouseHover(GameManager *this)
{
    SDL_Event *event = this->sceneManager->event;

    int x = event->motion.x;
    int y = event->motion.y;

    for (size_t i = 0; i < this->sceneManager->current->objCount; i++)
    {
        Object *obj = &this->sceneManager->current->objects[i];

        if (obj->isHover)
        {
            obj->isHover = SDL_FALSE;
            obj->OnExit(this, obj);
        }

        if (!obj->isButton || obj->layer != this->sceneManager->layerCurrent)
        {
            continue;
        }

        if (obj->rect != NULL &&
            obj->rect->x <= x && x <= obj->rect->x + obj->rect->w &&
            obj->rect->y <= y && y <= obj->rect->y + obj->rect->h)
        {
            obj->isHover = SDL_TRUE;
            obj->OnHover(this, obj);
        }
    }
}