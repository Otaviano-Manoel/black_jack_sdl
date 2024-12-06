#include <Game_Play.h>

static void GamePlay_Start(GamePlay *this);
static void GamePlay_Change_Turn(GamePlay *this);

GamePlay *Game_Play_Init()
{
    GamePlay *this = SDL_malloc(sizeof(GamePlay));
    this->Change_Turn = GamePlay_Change_Turn;
    this->Play_Start = GamePlay_Start;
    this->player[0] = Player_Init();
    SDL_strlcpy(this->player[0]->name, "Goku", MAX_LENGTH_NAME);
    this->player[1] = Player_Init();
    SDL_strlcpy(this->player[1]->name, "Vegeta", MAX_LENGTH_NAME);
    this->deck = Deck_Init();
    return this;
}

static void GamePlay_Start(GamePlay *this)
{
    this->deck->Shuffle(this->deck);
    this->turn = 0;
    this->player[0]->Start_Game(this->player[0]);
    this->player[1]->Start_Game(this->player[1]);
}

static void GamePlay_Change_Turn(GamePlay *this)
{
    this->turn = this->turn ? 0 : 1;
}

void GamePlay_Free(GamePlay *this)
{
    SDL_free(this->player[0]);
    SDL_free(this->player[1]);
    Deck_Free(this->deck);
    SDL_free(this->deck);
}