#include <Game_Event.h>
#include <Hit_Card_Animation.h>

static void Game_OnDraw(GameManager *manager, Player *p, SDL_bool isP1);

void Game_OnInit(GameManager *this)
{
    this->gamePlay->Play_Start(this->gamePlay);

    for (size_t i = 0; i < 2; i++)
    {
        Game_OnDraw(this, this->gamePlay->player[0], SDL_TRUE);
        Game_OnDraw(this, this->gamePlay->player[1], SDL_FALSE);
    }
}

void Game_OnHit_P1(GameManager *manager, Object *this)
{
    (void)this;
    Game_OnDraw(manager, manager->gamePlay->player[0], SDL_TRUE);
}

void Game_OnHit_P2(GameManager *manager, Object *this)
{
    (void)this;
    Game_OnDraw(manager, manager->gamePlay->player[1], SDL_FALSE);
}

void Game_OnStand(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;
}

void Game_OnExit(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;
}

static void Game_OnDraw(GameManager *manager, Player *p, SDL_bool isP1)
{
    Card *c = Deck_DrawCard(manager->gamePlay->deck);
    p->Add_Card(p, c);
    Hit_Card_Animation_Run(manager, c, isP1);
}