#include <CPU.h>

static SDL_bool Cpu_IsHit_DifficultyEasy(Player *p, GameManager *manager);

SDL_bool Cpu_IsHit(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return Cpu_IsHit_DifficultyEasy(p, manager);

    return SDL_FALSE;
}

SDL_bool Cpu_IsStand(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return p->totalValueCards > manager->gamePlay->player[0]->totalValueCards;

    return SDL_FALSE;
}

static SDL_bool Cpu_IsHit_DifficultyEasy(Player *p, GameManager *manager)
{
    return p->totalValueCards < 17 || p->totalValueCards < manager->gamePlay->player[0]->totalValueCards;
}