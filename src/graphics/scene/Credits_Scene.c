#include <Credits_Scene.h>
#include <Credit_Event.h>

static void Credit_SetVisible(Scene *scene, SDL_bool visible);
static void UpdateGifFrame(Object *obj, SDL_Renderer *renderer);
static char *Author()
{
    return "Created by:\n - Otaviano Manoel\nGitHub :\n - Repository: [Black Jack SDL]\n   (https://github.com/Otaviano-Manoel/black_jack_sdl)";
    //          return "Criado por: \n - Otaviano Manoel \n \n GitHub: \n - Repositorio: [Black Jack SDL] \n (https://github.com/Otaviano-Manoel/black_jack_sdl)";
}

static char *Graphics()
{
    return "Graphics:\n Freepik(freepik.com):\n  - @stockgiu\n  - @bearicons\n  - @rawpixel.com\n  - @iyikon\n  - @freepik\n  - @juicy_fish\nOther Sources:\n  - Andrew Tidey(andrewtidey.blogspot.co.uk)";
}
static char *Mixer()
{
    return "Music:\n Free Music Archive(freemusicarchive.org):\n  - Zane Little ";
}

static char *Thanks()
{
    return "A special thanks to my brother,\nGeorge Paulino, for always being by my side,\nsupporting me and believing in my potential.\nYour help was essential in making this project\na reality.";
}

static char *Conclusion()
{
    return "This is just the beginning!\n If you have suggestions or feedback,\n visit the GitHub repository\n and contribute to the development.\n Your input makes a difference!";
}

void Credit_Visible(Scene *scene)
{
    Credit_SetVisible(scene, SDL_TRUE);
}

void Credit_Hide(Scene *scene)
{
    Credit_SetVisible(scene, SDL_FALSE);
}

static void Credit_SetVisible(Scene *scene, SDL_bool visible)
{
    for (size_t i = 0; i < scene->objCount; i++)
    {
        Object *obj = scene->objects[i];

        if (obj->layer == 5)
        {
            obj->isVisible = visible;
        }
    }
}

void Credit_Draw(GameManager *this)
{
    Object *obj = NULL;

    // Obj
    obj = Obj_CreateWithImage(this, "background_dark.bmp", "creditback", 5, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, 128, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "background_dark.bmp", "creditbackdark", 5, 174, 0, 933, MAX_HEIGHT_WINDOW, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "close.bmp", "creditclose", 5, 1050, 20, 40, 40, 255, SDL_TRUE, SDL_TRUE, Credit_Event_OnClick_Close);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/banners", "f5376484900944eabc667d5540289309l7qesnaO9ufsR6PC-", "anim-0", 255, 35, 2, 546, 20, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-1", 255, 116, 1, 200, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-2", 255, 116, 1, 330, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-3", 255, 116, 1, 450, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-4", 255, 116, 1, 570, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-5", 255, 116, 1, 690, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-6", 255, 116, 1, 820, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithGif(this, "gifs/naipes", "f829255745cf4340d114cb5e68a9c584fEcEtV1qFbedeeoW-", "anim-7", 255, 116, 1, 950, 567, 140, 140, 5);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithImage(this, "scroll.bmp", "scroll", 5, 1150, 300, 90, 90, 255, SDL_TRUE, SDL_FALSE, NULL);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Author(), "font/MontserratAlternates-Medium.ttf", "txt-0", 5, 26, 250, 200, 40, 255);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Graphics(), "font/MontserratAlternates-Medium.ttf", "txt-1", 5, 26, 250, 150, 40, 0);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Mixer(), "font/MontserratAlternates-Medium.ttf", "txt-2", 5, 26, 250, 200, 40, 0);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Thanks(), "font/MontserratAlternates-Medium.ttf", "txt-3", 5, 26, 275, 200, 40, 0);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    obj = Obj_CreateWithText(this, NULL, (SDL_Color){255, 255, 255, 255}, Conclusion(), "font/MontserratAlternates-Medium.ttf", "txt-4", 5, 26, 275, 200, 40, 0);
    this->sceneManager->current->AddObj(this->sceneManager->current, obj);

    Credit_Hide(this->sceneManager->current);
}

void Credit_Update(GameManager *this)
{
    Credit_RunAnim(this);
}

void Credit_RunAnim(GameManager *this)
{
    Scene *credit = this->sceneManager->current;
    Object *obj = NULL;
    int i = 0;
    char tag[20];
    snprintf(tag, 20, "anim-%d", (int)i);

    while ((obj = Scene_FindTag(credit, tag)))
    {
        UpdateGifFrame(obj, this->sceneManager->renderer);
        snprintf(tag, 20, "anim-%d", (int)++i);
    }
}

static void UpdateGifFrame(Object *obj, SDL_Renderer *renderer)
{
    obj->gif->duplicate_current++;

    if ((obj->gif->duplicate_current - obj->gif->duplicate) == 0)
    {
        obj->gif->UpdateFrame(renderer, obj);
        obj->gif->duplicate_current = 0;
    }
}
