#include <Card.h>

Card *Card_Init(Naipe n, Value v)
{
    Card *c = (Card *)malloc(sizeof(Card));
    c->naipe = n;
    c->value = v;
    c->isFaceUp = SDL_FALSE;
    return c;
}