#include <Graphics_Utils.h>

void ClearRender(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void UpdateObjectScale(SceneManager *this)
{
    for (size_t i = 0; i < this->current->objCount; i++)
    {
        Object *obj = this->current->objects[i];

        if (obj->rect)
            obj->Create_Rect(this->window, obj, obj->rectOrigin->x, obj->rectOrigin->y, obj->rectOrigin->w, obj->rectOrigin->h);

        if (obj->text)
        {
            for (int j = 0; j < obj->text->lines; j++)
            {
                obj->text->SetFont(this->window, obj->text, obj->text->file, obj->text->ptSize);
                obj->text->SetText(this->renderer, obj->text, obj->text->color, obj->text->text[j], j);
                obj->text->SetPosition(this->window, obj, obj->text, obj->text->textRectOrigin[j]->x, obj->text->textRectOrigin[j]->y, j);
            }
        }
    }
}

void RenderObject(SDL_Renderer *renderer, Object *obj)
{
    if (!obj->isVisible)
        return; // Skip invisible objects

    if (obj->texture)
    {
        SDL_SetTextureAlphaMod(obj->texture, obj->opacity);
        if (SDL_RenderCopy(renderer, obj->texture, NULL, obj->rect) != 0)
        {
            SDL_Log("Erro ao renderizar objeto: %s", SDL_GetError());
            return;
        }
    }

    if (obj->text)
    {
        for (int i = 0; i < obj->text->lines; i++)
        {
            SDL_SetTextureAlphaMod(obj->text->textTexture[i], obj->opacity);

            if (SDL_RenderCopy(renderer, obj->text->textTexture[i], NULL, obj->text->textRect[i]) != 0)
            {
                SDL_Log("Erro ao renderizar texto: %s", SDL_GetError());
            }
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
            Object *obj = manager->sceneManager->current->objects[i];

            RenderObject(manager->sceneManager->renderer, obj);
        }
    }
}