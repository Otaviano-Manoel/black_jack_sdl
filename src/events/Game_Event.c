#include <Game_Event.h>
#include <Menu_Scene.h>
#include <Hit_Card_Animation.h>
#include <Game_Points_Present_Render.h>
#include <Game_Turn_Name_Present_Render.h>
#include <Rules.h>

static void Game_OnDraw(GameManager *manager, Player *p, SDL_bool isP1);
static void Game_OnChangedTurn(GameManager *manager, SDL_bool isP1);

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

    if (!Rule_ValidateYourTurn(manager, 0))
        return;

    Game_OnDraw(manager, manager->gamePlay->player[0], SDL_TRUE);
    Game_OnChangedTurn(manager, SDL_TRUE);
}

void Game_OnHit_P2(GameManager *manager, Object *this)
{
    (void)this;

    if (!Rule_ValidateYourTurn(manager, 1))
        return;

    Game_OnDraw(manager, manager->gamePlay->player[1], SDL_FALSE);
    Game_OnChangedTurn(manager, SDL_FALSE);
}

void Game_OnStand_P1(GameManager *manager, Object *this)
{
    (void)this;

    if (!Rule_ValidateYourStand(manager, 0))
        return;

    Game_OnChangedTurn(manager, SDL_TRUE);
}

void Game_OnStand_P2(GameManager *manager, Object *this)
{
    (void)this;

    if (!Rule_ValidateYourStand(manager, 1))
        return;

    Game_OnChangedTurn(manager, SDL_FALSE);
}

void Game_OnExit(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->ChangeScene(manager, Menu_Init());
}

static void Game_OnChangedTurn(GameManager *manager, SDL_bool isP1)
{
    manager->gamePlay->turn = isP1 ? 1 : 0;
    Game_Turn_Name_Present_Render(manager, manager->gamePlay->player[manager->gamePlay->turn]);
}

static void Game_OnDraw(GameManager *manager, Player *p, SDL_bool isP1)
{
    Card *c = Deck_DrawCard(manager->gamePlay->deck);
    p->Add_Card(p, c);
    Hit_Card_Animation_Run(manager, c, isP1);
    Game_Points_Present_Render(manager, p, isP1);
}