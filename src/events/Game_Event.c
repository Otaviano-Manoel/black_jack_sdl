#include <Game_Event.h>

void Game_OnInit(GameManager *this)
{
    this->gamePlay->Play_Start(this->gamePlay);
}

void Game_OnHit(GameManager *manager, Object *this)
{
    (void)manager;
    (void)this;

    Player *p = manager->gamePlay->player[manager->gamePlay->turn];
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