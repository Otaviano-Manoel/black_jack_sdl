#include <Graphics_Utils.h>

void ClearRender(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void RenderObject(SDL_Renderer *renderer, Object *obj)
{
    SDL_SetTextureAlphaMod(obj->texture, obj->opacity);
    if (SDL_RenderCopy(renderer, obj->texture, NULL, obj->rect) != 0)
    {
        SDL_Log("Erro ao renderizar objeto: %s", SDL_GetError());
    }

    if (obj->text->isTextLoaded)
    {
        SDL_SetTextureAlphaMod(obj->text->textTexture, obj->opacity);
        if (SDL_RenderCopy(renderer, obj->text->textTexture, NULL, obj->text->textRect) != 0)
        {
            SDL_Log("Erro ao renderizar objeto: %s", SDL_GetError());
        }
    }
}

void PresentRenderer(SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

void RenderObjectsInScene(GameManager *manager)
{
    if (manager->sceneManager->isCurrentSet)
    {
        for (size_t i = 0; i < manager->sceneManager->current->objCount; i++)
        {
            Object *obj = &manager->sceneManager->current->objects[i];

            RenderObject(manager->sceneManager->renderer, obj);
        }
    }
}