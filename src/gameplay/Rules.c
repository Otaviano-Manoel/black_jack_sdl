#include <Rules.h>

SDL_bool Rule_ValidateYourTurn(GameManager *manager, int isMyTurn)
{
    return manager->gamePlay->turn == isMyTurn;
}
