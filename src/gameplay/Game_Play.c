#include <Game_Play.h>

static void GamePlay_Start(GamePlay *this);
static void GamePlay_Change_Turn(GamePlay *this);

GamePlay *Game_Play_Init()
{
    GamePlay *this = SDL_malloc(sizeof(GamePlay));
    this->Change_Turn = GamePlay_Change_Turn;
    this->Play_Start = GamePlay_Start;
    this->countMatche = 0;
    this->player[0] = Player_Init();
    SDL_strlcpy(this->player[0]->name, "ONE", MAX_LENGTH_NAME);
    this->player[1] = Player_Init();
    SDL_strlcpy(this->player[1]->name, "TWO", MAX_LENGTH_NAME);
    this->deck = Deck_Init();
    return this;
}

int GamePlay_GetWinner(GameManager *this)
{
    return this->gamePlay->player[0]->isWinner ? 0 : 1;
}

static void GamePlay_Start(GamePlay *this)
{
    this->deck->Shuffle(this->deck);
    this->turn = this->countMatche % 2 == 0 ? 0 : 1;
    this->player[0]->Start_Game(this->player[0]);
    this->player[1]->Start_Game(this->player[1]);
    this->countTurn = 0;
    this->countMatche++;
}

static void GamePlay_Change_Turn(GamePlay *this)
{
    this->countTurn++;
    this->turn = this->turn == 0 ? 1 : 0;
}

void GamePlay_Free(GamePlay *this)
{
    SDL_free(this->player[0]);
    SDL_free(this->player[1]);
    Deck_Free(this->deck);
    SDL_free(this->deck);
}