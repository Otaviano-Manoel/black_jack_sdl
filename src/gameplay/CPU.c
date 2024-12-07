#include <CPU.h>

SDL_bool Cpu_IsHit(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return p->totalValueCards < 17 || p->totalValueCards < manager->gamePlay->player[0]->totalValueCards;

    return SDL_FALSE;
}

SDL_bool Cpu_IsStand(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return p->totalValueCards > manager->gamePlay->player[0]->totalValueCards;

    return SDL_FALSE;
}