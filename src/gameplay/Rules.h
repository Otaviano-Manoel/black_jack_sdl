#pragma once

#include <Game_Manager.h>

SDL_bool Rule_ValidateYourTurn(GameManager *manager, int isMyTurn);
SDL_bool Rule_ValidateYourStand(GameManager *manager, int isMyTurn);
SDL_bool Rule_ValidateVictory(GameManager *manager);
SDL_bool Rule_ValidateLoser(GameManager *manager);