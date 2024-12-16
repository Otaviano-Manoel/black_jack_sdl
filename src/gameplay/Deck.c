#include <Deck.h>

static void Build_Deck(Deck *deck);
static void Shuffle(Deck *deck);

Deck *Deck_Init()
{
    Deck *deck = SDL_malloc(sizeof(Deck));
    deck->countDraw = 0;
    Build_Deck(deck);
    deck->Shuffle = Shuffle;
    return deck;
}

void Deck_Free(Deck *deck)
{
    for (size_t i = 0; i < MAX_DECK; i++)
    {
        SDL_free(deck->cards[i]);
    }
}

Card *Deck_DrawCard(Deck *deck)
{
    if (deck->countDraw < MAX_DECK)
    {
        Card *c = deck->cards[deck->countDraw];
        deck->countDraw++;
        return c;
    }

    return NULL;
}

static void Build_Deck(Deck *deck)
{
    for (Naipe i = 0; i < 4; i++)
    {
        for (Value j = 1; j <= 13; j++)
        {
            Card *card = Card_Init(i, j);
            deck->cards[deck->countDraw] = card;
            deck->countDraw++;
        }
    }

    // Colocar dois Jocker no deck
    deck->cards[52] = Card_Init(0, 14); // Jocker Preto
    deck->cards[53] = Card_Init(0, 15); // Jocker Vermelho
    deck->countDraw = 0;
}

static void Shuffle(Deck *deck)
{
    for (int i = 0; i < MAX_DECK; i++)
    {
        int j = rand() % (i + 1);

        Card *temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}