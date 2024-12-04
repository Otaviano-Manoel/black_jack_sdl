#pragma once

#include <Game_Manager.h>

typedef enum Naipe
{
    Diamond,
    Clubs,
    Spades,
    hearts,
    Jocker
} Naipe;

typedef enum Value
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Jocker_Dark,
    Jocker_Red
} Value;

typedef struct Card
{
    Value value;
    Naipe naipe;
    SDL_bool isFaceUp;
} Card;

Card *Card_Init(Naipe n, Value v);