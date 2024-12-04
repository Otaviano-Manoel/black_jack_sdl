#pragma once

#include <Game_Manager.h>

#define MAX_DECK 54

typedef struct Deck
{
    Card *cards[MAX_DECK];
    int countDraw;
    void (*Shuffle)(struct Deck *deck);
} Deck;

Deck *Deck_Init();
Card *Deck_DrawCard(Deck *deck);
void Deck_Free(Deck *deck);