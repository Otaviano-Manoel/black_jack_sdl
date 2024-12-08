#pragma once

#include <Game_Manager.h>

#define MAX_LENGTH_NAME 8

typedef struct Player
{
    char name[MAX_LENGTH_NAME];
    SDL_bool isEditName;
    SDL_bool isPlayer;
    SDL_bool isP1;
    SDL_bool isWinner;

    Card *hand[6];
    size_t countCardsInHand;
    size_t totalValueCards;
    size_t totalWinner;

    void (*Add_Card)(Player *p, Card *card);
    void (*SetName)(struct Player *this, char name[20]);
    void (*Start_Game)(Player *p);
} Player;

Player *Player_Init();