#pragma once

#include <Game_Manager.h>

void ClearRender(SDL_Renderer *renderer);
void UpdateObjectScale(SceneManager *this);
void RenderObject(SDL_Renderer *renderer, Object *obj);
void PresentRenderer(SDL_Renderer *renderer, SDL_Window *window);
void RenderObjectsInScene(GameManager *manager);