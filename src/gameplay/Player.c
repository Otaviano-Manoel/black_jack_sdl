#include <Player.h>

static void Player_SetName(Player *this, char name[20]);

Player *Player_Init()
{
    Player *player = malloc(sizeof(Player));
    player->SetName = Player_SetName;
    SDL_strlcpy(player->name, "Name", 20);
    player->isEditName = SDL_FALSE;
    return player;
}

static void Player_SetName(Player *this, char name[20])
{
    SDL_strlcpy(this->name, name, 20);
}