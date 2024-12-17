#include <Event_Manager.h>

void Event_Wait(GameManager *this)
{
    SDL_Event *event = this->sceneManager->event;

    if (this->isEnableTextInput)
    {
        HandleTextInput(this);
        return;
    }

    while (SDL_PollEvent(event))
    {
        int index;

        Event_General(event, this);

        switch (event->type)
        {
        case SDL_MOUSEBUTTONDOWN:
            index = SceneManager_GetObjisHover(this);
            if (index != -1)
            {
                Object *obj = this->sceneManager->current->objects[index];
                if (obj->OnAnimClick != NULL)
                    obj->OnAnimClick(this, obj);
                if (obj->OnClick != NULL)
                    obj->OnClick(this, obj);
            }
            break;
        case SDL_MOUSEMOTION:
            Object_Interaction_GetMouseHover(this);
            break;

        default:
            break;
        }
    }
}

void Event_General(SDL_Event *event, GameManager *this)
{
    switch (event->type)
    {
    case SDL_QUIT:
        this->quit = SDL_TRUE;
        break;

    case SDL_KEYDOWN:
        if (event->key.keysym.sym == SDLK_RETURN && (event->key.keysym.mod & KMOD_ALT))
        {
            Window_Change_Screen_OnFullScreen(this->sceneManager);
        }
        break;
    default:
        break;
    }
}