#include <Text_Input_Event.h>

void HandleTextInput(GameManager *this)
{
    SDL_Event *event = this->sceneManager->event;
    Player *player = this->gamePlay->player[0]->isEditName ? this->gamePlay->player[0] : this->gamePlay->player[1];

    char temp[32];
    strcpy(temp, this->gamePlay->player[0]->isEditName ? "P1" : "P2");
    Object *obj = Scene_FindTag(this->sceneManager->current, temp);

    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            this->quit = SDL_TRUE;
        }

        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_BACKSPACE && strlen(player->name) > 0)
            {
                player->name[strlen(player->name) - 1] = '\0';

                if (strlen(player->name) == 0)
                {
                    obj->text->isTextLoaded = SDL_FALSE;
                }
            }
            if (event->key.keysym.sym == SDLK_RETURN && strlen(player->name) > 0)
            {
                this->sceneManager->layerCurrent = 2;
                player->isEditName = SDL_FALSE;
                this->isEnableTextInput = SDL_FALSE;
            }
        }
        else if (event->type == SDL_TEXTINPUT)
        {
            if (strlen(player->name) < MAX_LENGTH_NAME)
                strncat(player->name, event->text.text, sizeof(player->name) - strlen(player->name) - 1);
        }
        if (strlen(player->name) > 0)
        {
            obj->text->isTextLoaded = SDL_TRUE;
            Setting_UpdateNamePlayer(this, player, obj);
        }
    }
}