#pragma once

#include <Game_Manager.h>

typedef struct GamePlay
{
    Deck *deck;
    Player *player[2];
    int turn;
    int countTurn;
    int countMatche;

    void (*Play_Start)(GamePlay *this);
    void (*Change_Turn)(GamePlay *this);
} GamePlay;

GamePlay *Game_Play_Init();
Player *GamePlay_GetWinner(GameManager *this);
void GamePlay_Free(GamePlay *this);
