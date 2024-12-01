#include <ObjectEvent.h>

static void ObjectEvent_OnHover(GameManager *manager, Object *this);
static void ObjectEvent_OnExit(GameManager *manager, Object *this);
static void ObjectEvent_AnimClick(GameManager *manager, Object *this);
static void ObjectEvent_UpdateAnimClick(GameManager *manager, Object *this);

void RegisterEvent(Object *this,
                   void (*OnHover)(GameManager *manager, struct Object *this),
                   void (*OnExit)(GameManager *manager, struct Object *this))
{
    if (OnHover == NULL)
    {
        this->OnHover = ObjectEvent_OnHover;
    }
    else
    {
        this->OnHover = OnHover;
    }

    if (OnExit == NULL)
    {
        this->OnLeave = ObjectEvent_OnExit;
    }
    else
    {
        this->OnLeave = OnExit;
    }

    this->OnAnimClick = ObjectEvent_AnimClick;
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

static void ObjectEvent_AnimClick(GameManager *manager, Object *this)
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
    SDL_SetTextureAlphaMod(this->texture, this->opacity);

    SDL_RenderCopy(manager->sceneManager->renderer, this->texture, NULL, this->rect);

    if (this->text->isTextLoaded)
    {
        SDL_SetTextureAlphaMod(this->text->textTexture, this->opacity);
        SDL_RenderCopy(manager->sceneManager->renderer, this->text->textTexture, NULL, this->text->textRect);
    }

    SDL_RenderPresent(manager->sceneManager->renderer);
    SDL_UpdateWindowSurface(manager->sceneManager->window);
}
