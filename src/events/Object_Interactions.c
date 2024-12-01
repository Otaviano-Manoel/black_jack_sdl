#include <Object_Interactions.h>

void Object_Interaction_GetMouseHover(GameManager *this)
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
            if (obj->OnLeave != NULL)
                obj->OnLeave(this, obj);
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
            if (obj->OnHover != NULL)
                obj->OnHover(this, obj);
        }
    }
}

int SceneManager_GetObjisHover(struct GameManager *this)
{
    for (size_t i = 0; i < this->sceneManager->current->objCount; i++)
    {
        Object *obj = &this->sceneManager->current->objects[i];

        if (obj->isHover)
        {
            return (int)i;
        }
    }
    return -1;
}