#pragma once

#include <Game_Manager.h>

typedef struct GamePlay
{
    Deck *deck;
    Player *player[2];
    int turn;
    int countTurn;

    void (*Play_Start)(GamePlay *this);
    void (*Change_Turn)(GamePlay *this);
} GamePlay;

GamePlay *Game_Play_Init();
void GamePlay_Free(GamePlay *this);
