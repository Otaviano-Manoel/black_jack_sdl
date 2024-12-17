#include <Game_Points_Present_Render.h>

void Game_Points_Present_Render(GameManager *manager, Player *player, SDL_bool isP1)
{
    char buffer[256];
    snprintf(buffer, 256, "Points: %d", (int)player->totalValueCards);

    char *tag = isP1 ? "p-p1" : "p-p2";

    Object *obj_Points = Scene_FindTag(manager->sceneManager->current, tag);
    obj_Points->text->SetText(manager->sceneManager->renderer, obj_Points->text, obj_Points->text->color, buffer, 0);
}