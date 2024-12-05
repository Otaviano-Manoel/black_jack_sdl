#include <Card.h>

static char *Card_GetNaipeToString(Naipe n);

Card *Card_Init(Naipe n, Value v)
{
    Card *c = (Card *)malloc(sizeof(Card));
    c->naipe = n;
    c->value = v;
    c->isFaceUp = SDL_FALSE;
    return c;
}

char *Card_GetNameFileBMP(Card *card)
{
    char *name = (char *)malloc(50 * sizeof(char));

    if (card->value == Jocker_Dark || card->value == Jocker_Red)
    {
        if (card->naipe == Clubs || card->naipe == Diamond)
        {
            return "cards/joker_red.bmp";
        }
        else if (card->naipe == Spades || card->naipe == Hearts)
        {
            return "cards/joker_black.bmp";
        }
    }
    else
    {
        snprintf(name, 50, "cards/%s_%d.bmp", Card_GetNaipeToString(card->naipe), card->value);
        return name;
    }
    return NULL;
}

static char *Card_GetNaipeToString(Naipe n)
{
    switch (n)
    {
    case Diamond:
        return "diamond";
    case Hearts:
        return "hearts";
    case Clubs:
        return "clubs";
    case Spades:
        return "spades";
    default:
        return "default";
    }
}