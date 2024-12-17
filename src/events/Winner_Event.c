#include <Winner_Event.h>
#include <Game_Scene.h>
#include <Menu_Scene.h>

void Winner_OnInit(GameManager *this)
{
    Player *p1 = this->gamePlay->player[0];
    Player *p2 = this->gamePlay->player[1];

    if (p1->isWinner && p2->isWinner)
    {
        return;
    }

    Player *p = GamePlay_GetWinner(this);
    p->totalWinner++;
}

void Winner_OnPlayAgain(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->ChangeScene(manager, Game_Scene_Init());
    Game_OnInit(manager);
}
void Winner_OnMainMenu(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->ChangeScene(manager, Menu_Scene_Init());
}