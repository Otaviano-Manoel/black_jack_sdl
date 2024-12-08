#include <CPU.h>

static SDL_bool Cpu_IsHit_DifficultyEasy(Player *p, GameManager *manager);
static SDL_bool Cpu_IsHit_DifficultyMedium(Player *p, GameManager *manager);
static SDL_bool Cpu_IsHit_DifficultyHard(Player *p, GameManager *manager);
static SDL_bool Cpu_IsHit_DifficultyHard_StyleClassic(Player *p, GameManager *manager);
static SDL_bool Cpu_IsHit_DifficultyHard_StyleModern(Player *p, GameManager *manager);

SDL_bool Cpu_IsHit(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return Cpu_IsHit_DifficultyEasy(p, manager);
    else if (manager->gameConfig->difficulty == DIFFICULTY_MEDIUM)
        return Cpu_IsHit_DifficultyMedium(p, manager);
    else if (manager->gameConfig->difficulty == DIFFICULTY_HARD)
        return Cpu_IsHit_DifficultyHard(p, manager);

    return SDL_FALSE;
}

SDL_bool Cpu_IsStand(GameManager *manager)
{
    Player *p = manager->gamePlay->player[1];

    if (manager->gameConfig->difficulty == DIFFICULTY_EASY)
        return p->totalValueCards > manager->gamePlay->player[0]->totalValueCards;

    return SDL_TRUE;
}

static SDL_bool Cpu_IsHit_DifficultyEasy(Player *p, GameManager *manager)
{
    return p->totalValueCards < 17 || p->totalValueCards <= manager->gamePlay->player[0]->totalValueCards;
}

static SDL_bool Cpu_IsHit_DifficultyMedium(Player *p, GameManager *manager)
{
    Card *c = manager->gamePlay->deck->cards[manager->gamePlay->deck->countDraw];
    return (p->totalValueCards + c->value) <= 21 || p->totalValueCards <= manager->gamePlay->player[0]->totalValueCards;
}

static SDL_bool Cpu_IsHit_DifficultyHard(Player *p, GameManager *manager)
{
    if (manager->gameConfig->style == STYLE_CLASSIC)
    {
        return Cpu_IsHit_DifficultyHard_StyleClassic(p, manager);
    }
    else if (manager->gameConfig->style == STYLE_MODERN)
    {
        return Cpu_IsHit_DifficultyHard_StyleModern(p, manager);
    }
    return SDL_FALSE;
}

static SDL_bool Cpu_IsHit_DifficultyHard_StyleClassic(Player *p, GameManager *manager)
{
    Card *c1 = manager->gamePlay->deck->cards[manager->gamePlay->deck->countDraw];
    Card *c2 = manager->gamePlay->deck->cards[manager->gamePlay->deck->countDraw + 1];

    int playerTotal = (int)p->totalValueCards;
    int opponentTotal = (int)manager->gamePlay->player[0]->totalValueCards;

    // Prioridade: Se a próxima carta faz 21, sempre pega
    if (playerTotal + (int)c1->value == 21)
    {
        return SDL_TRUE;
    }

    // Avaliação caso a soma com c1 seja menor que 21
    if (playerTotal + (int)c1->value < 21 && playerTotal > opponentTotal)
    {
        // Se o oponente irá estourar com c1
        if (opponentTotal + (int)c1->value > 21)
        {
            return SDL_FALSE;
        }
        // Se o oponente irá estourar com c2
        else if (opponentTotal + (int)c2->value > 21)
        {
            return SDL_TRUE;
        }

        // Avaliação especial para Ás
        if (c1->value == Ace && (playerTotal + 11 <= 21 || playerTotal + 1 <= 21))
        {
            return SDL_TRUE;
        }

        // Comparação direta entre c1 e c2
        return c1->value >= c2->value ? SDL_TRUE : SDL_FALSE;
    }

    return playerTotal <= opponentTotal;
}

static SDL_bool Cpu_IsHit_DifficultyHard_StyleModern(Player *p, GameManager *manager)
{
    Card *c1 = manager->gamePlay->deck->cards[manager->gamePlay->deck->countDraw];

    int playerTotal = (int)p->totalValueCards;
    // int opponentTotal = (int)manager->gamePlay->player[0]->totalValueCards;

    // Se a próxima carta faz o jogador atingir 21, pega
    if (playerTotal + (int)c1->value == 21)
    {
        return SDL_TRUE;
    }

    // Se o oponente já jogou
    if (manager->gamePlay->countTurn != 0)
    {
        // Se a soma com c1 ainda está abaixo de 21, pega a carta
        if (playerTotal + (int)c1->value < 21)
        {
            return SDL_TRUE;
        }
        // Caso contrário, decide parar (ou você pode adicionar mais lógica aqui)
        return SDL_FALSE;
    }
    else // Oponente ainda não jogou
    {
        // Simula o total possível do oponente com as próximas cartas
        if (playerTotal + (int)c1->value > 21 && c1->value != Jocker_Dark && c1->value != Jocker_Red)
        {
            return SDL_FALSE;
        }

        int opponentTemp = 0;
        for (int i = 0; i < 4; i++)
        {
            Card *temp = manager->gamePlay->deck->cards[manager->gamePlay->deck->countDraw + i];

            // Trata o valor do Ás e exclui Jokers
            if (temp->value == Ace)
            {
                opponentTemp += (opponentTemp + 11 <= 21) ? 11 : 1;
            }
            else if (temp->value != Jocker_Dark && temp->value != Jocker_Red)
            {
                opponentTemp += (int)temp->value;
            }

            // Decide se deve continuar
            if (opponentTemp > playerTotal)
            {
                return SDL_TRUE; // CPU tenta ganhar antes do oponente alcançá-la
            }
            else if (opponentTemp > 21)
            {
                return SDL_FALSE; // Oponente estourou, CPU pode parar
            }
        }

        // Se chegou aqui, pega a carta caso esteja abaixo de 21
        if (playerTotal + (int)c1->value < 21)
        {
            return SDL_TRUE;
        }
    }
    return SDL_FALSE;
}