#include <Game_Play.h>

static void Game_Play_Start(GamePlay *this);
static void Change_Turn(GamePlay *this);

GamePlay *Game_Play_Init()
{
    GamePlay *this = SDL_malloc(sizeof(GamePlay));
    this->Change_Turn = Change_Turn;
    this->Play_Start = Game_Play_Start;
    this->player[0] = Player_Init();
    this->player[1] = Player_Init();
    this->deck = Deck_Init();
    return this;
}

static void Game_Play_Start(GamePlay *this)
{
    this->deck->Shuffle(this->deck);
    this->turn = 0;
    this->player[0]->Start_Game(this->player[0]);
    this->player[1]->Start_Game(this->player[1]);
}

static void Change_Turn(GamePlay *this)
{
    this->turn = this->turn ? 0 : 1;
}

void Game_Play_Free(GamePlay *this)
{
    SDL_free(this->player[0]);
    SDL_free(this->player[1]);
    Deck_Free(this->deck);
    SDL_free(this->deck);
}