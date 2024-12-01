#include <EventManager.h>

void Event_Wait(GameManager *this)
{
    SDL_Event *event = this->sceneManager->event;
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            this->quit = SDL_TRUE;
        }
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            int index = SceneManager_GetObjisHover(this);

            if (index != -1)
            {
                Object *obj = &this->sceneManager->current->objects[index];
                if (obj->OnAnimClick != NULL)
                    obj->OnAnimClick(this, obj);
                if (obj->OnClick != NULL)
                    obj->OnClick(this, obj);
            }
        }
        if (event->type == SDL_MOUSEMOTION)
        {
            Object_Interaction_GetMouseHover(this);
        }
    }
}