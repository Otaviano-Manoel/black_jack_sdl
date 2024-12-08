#include <Winner_Event.h>
#include <Game_Scene.h>
#include <Menu_Scene.h>

void Winnar_OnInit(GameManager *this)
{
    Player *p = this->gamePlay->player[GamePlay_GetWinner(this)];
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