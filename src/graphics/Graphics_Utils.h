#pragma once

#include <GameManager.h>

void ClearRender(SDL_Renderer *renderer);
void RenderObject(SDL_Renderer *renderer, Object *obj);
void PresentRenderer(SDL_Renderer *renderer, SDL_Window *window);
void RenderObjectsInScene(GameManager *manager);