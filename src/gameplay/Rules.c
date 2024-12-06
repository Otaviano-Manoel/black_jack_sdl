#include <Rules.h>

SDL_bool Rule_ValidateYourTurn(GameManager *manager, int isMyTurn)
{
    return manager->gamePlay->turn == isMyTurn;
}

SDL_bool Rule_ValidateYourStand(GameManager *manager, int isMyTurn)
{
    Player *player = manager->gamePlay->player[isMyTurn];
    Player *opponent = manager->gamePlay->player[isMyTurn == 0 ? 1 : 0];

    return player->totalValueCards > opponent->totalValueCards;
}