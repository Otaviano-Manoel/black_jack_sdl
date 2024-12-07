#include <Player.h>
#include <Rules.h>

static void Player_SetName(Player *this, char name[20]);
static void Player_Start_Game(Player *p);
static void Player_Add_Card(Player *p, Card *card);

Player *Player_Init()
{
    Player *player = malloc(sizeof(Player));
    player->Add_Card = Player_Add_Card;
    player->SetName = Player_SetName;
    player->Start_Game = Player_Start_Game;
    SDL_strlcpy(player->name, "Name", MAX_LENGTH_NAME);
    player->isEditName = SDL_FALSE;
    player->countCardsInHand = 0;
    player->totalValueCards = 0;
    player->isPlayer = SDL_TRUE;
    player->isWinner = SDL_FALSE;
    return player;
}

static void Player_Add_Card(Player *p, Card *card)
{
    p->totalValueCards += (size_t)Rule_SomeValueCard(card);

    Rule_Ace(p);

    p->hand[p->countCardsInHand] = card;
    p->countCardsInHand++;
}

static void Player_Start_Game(Player *p)
{
    p->countCardsInHand = 0;
    p->totalValueCards = 0;
    for (size_t i = 0; i < 6; i++)
    {
        p->hand[i] = NULL;
    }
}

static void Player_SetName(Player *this, char name[20])
{
    SDL_strlcpy(this->name, name, 20);
}