#include <Rules.h>

static SDL_bool Rule_CheckWinner(Player *player, Player *opponent, GameConfig *config, int turnCount);

SDL_bool Rule_ValidateYourTurn(GameManager *manager, int isMyTurn)
{
    return manager->gamePlay->turn == isMyTurn;
}

SDL_bool Rule_ValidateYourStand(GameManager *manager, int isMyTurn)
{
    Player *player = manager->gamePlay->player[isMyTurn];
    Player *opponent = manager->gamePlay->player[isMyTurn == 0 ? 1 : 0];

    if (manager->gameConfig->style == STYLE_CLASSIC)
        return player->totalValueCards > opponent->totalValueCards;
    else
        return SDL_TRUE;
}

static SDL_bool Rule_CheckWinner(Player *player, Player *opponent, GameConfig *config, int turnCount)
{
    if (config->style == STYLE_CLASSIC)
    {
        return (player->totalValueCards == 21 || player->countCardsInHand == 5);
    }
    else if (config->style == STYLE_MODERN)
    {
        return (player->totalValueCards == 21) ||
               (turnCount == 2 && player->totalValueCards >= opponent->totalValueCards);
    }
    return SDL_FALSE;
}

SDL_bool Rule_ValidateVictory(GameManager *manager)
{

    Player *p1 = manager->gamePlay->player[0];
    Player *p2 = manager->gamePlay->player[1];

    p1->isWinner = Rule_CheckWinner(p1, p2, manager->gameConfig, manager->gamePlay->countTurn);
    p2->isWinner = Rule_CheckWinner(p2, p1, manager->gameConfig, manager->gamePlay->countTurn);

    return p1->isWinner || p2->isWinner;
}

SDL_bool Rule_ValidateLoser(GameManager *manager)
{
    Player *p1 = manager->gamePlay->player[0];
    Player *p2 = manager->gamePlay->player[1];

    p1->isWinner = p2->totalValueCards > 21;
    p2->isWinner = p1->totalValueCards > 21;

    return p1->isWinner || p2->isWinner;
}

int Rule_SomeValueCard(Card *card)
{
    if (card == NULL)
    {
        SDL_Log("A carta esta nula");
    }

    if (card->value == Ace)
        return 11;
    else if (card->value == Jocker_Dark || card->value == Jocker_Red)
        return 0;
    else
        return card->value;
}

void Rule_Ace(Player *p)
{
    if (p == NULL)
    {
        SDL_Log("A carta esta nula");
    }

    if (p->totalValueCards > 21)
    {
        for (size_t i = 0; i < p->countCardsInHand; i++)
        {
            Card *c = p->hand[i];
            if (c->value == Ace && !c->isFaceUp)
            {
                p->totalValueCards -= 10;
                c->isFaceUp = SDL_TRUE;

                if (p->totalValueCards < 21)
                    break;
            }
        }
    }
}