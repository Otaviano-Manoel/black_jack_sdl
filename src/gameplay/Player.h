#pragma once

#include <Game_Manager.h>

typedef struct Player
{
    char name[20];

    void (*SetName)(struct Player *this, char name[20]);
} Player;

Player *Player_Init();