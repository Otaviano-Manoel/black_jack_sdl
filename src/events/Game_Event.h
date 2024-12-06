#pragma once

#include <Game_Manager.h>

void Game_OnInit(GameManager *this);
void Game_OnHit_P1(GameManager *manager, Object *this);
void Game_OnHit_P2(GameManager *manager, Object *this);
void Game_OnStand_P1(GameManager *manager, Object *this);
void Game_OnStand_P2(GameManager *manager, Object *this);
void Game_OnExit(GameManager *manager, Object *this);