#include <Game_Turn_Name_Present_Render.h>

void Game_Turn_Name_Present_Render(GameManager *manager, Player *p)
{
    Object *obj_Turn = Scene_FindTag(manager->sceneManager->current, "turn-name");
    obj_Turn->text->SetText(manager->sceneManager->renderer, obj_Turn->text, obj_Turn->text->color, p->name, 0);
}