#include <Game_Manager.h>

static void SceneManager_init_SDL(SceneManager *this);
static void SceneManager_ChangeScene(GameManager *manager, Scene *next);
static void SceneManager_Start(GameManager *);
static void SceneManager_Update(GameManager *);
static void SceneManager_Quit(GameManager *);

SceneManager *SceneManager_Init()
{
    SceneManager *sceneManager = malloc(sizeof(SceneManager));
    sceneManager->event = (SDL_Event *)malloc(sizeof(SDL_Event));
    sceneManager->ChangeScene = SceneManager_ChangeScene;
    sceneManager->Start = SceneManager_Start;
    sceneManager->Update = SceneManager_Update;
    sceneManager->Quit = SceneManager_Quit;
    SceneManager_init_SDL(sceneManager);

    return sceneManager;
}

static void SceneManager_ChangeScene(GameManager *manager, Scene *next)
{
    if (manager->sceneManager->isCurrentSet)
    {
        manager->sceneManager->Quit(manager);
    }
    manager->sceneManager->current = next;
    manager->sceneManager->isCurrentSet = SDL_TRUE;
    manager->sceneManager->Start(manager);
}
static void SceneManager_Start(GameManager *manager)
{
    if (manager->sceneManager->isCurrentSet)
    {
        manager->sceneManager->current->Start(manager);
    }
}
static void SceneManager_Update(GameManager *manager)
{
    ClearRender(manager->sceneManager->renderer);
    RenderObjectsInScene(manager);
    PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window);
    Event_Wait(manager);
}

static void SceneManager_Quit(GameManager *manager)
{
    if (manager->sceneManager->isCurrentSet)
    {
        manager->sceneManager->current->Quit(manager);
    }
}

static void SceneManager_init_SDL(SceneManager *this)
{
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("21 Master", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, SDL_WINDOW_SHOWN);
    this->window = window;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer)
    {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        return;
    }
    if (TTF_Init() == -1)
    {
        SDL_Log("Erro ao inicializar SDL_ttf: %s", TTF_GetError());
        return;
    }
}

/*
void fadeSceneTransition(GameManager *manager, Uint32 duration) {
    Uint32 startTime = SDL_GetTicks();
    Uint8 alpha = 0;
    SDL_Surface *fadeSurface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);

    // Preencher a superfície com preto
    SDL_FillRect(fadeSurface, NULL, SDL_MapRGB(fadeSurface->format, 0, 0, 0));

    // Fade in
    while (alpha < 255) {
        SDL_RenderClear(manager->sceneManager->renderer);

        // Renderizar a cena atual
        if (manager->sceneManager->current != NULL) {
            manager->sceneManager->current->Render(manager);
        }

        // Ajustar a opacidade
        SDL_SetSurfaceAlphaMod(fadeSurface, alpha);
        SDL_Texture *fadeTexture = SDL_CreateTextureFromSurface(manager->sceneManager->renderer, fadeSurface);
        SDL_RenderCopy(manager->sceneManager->renderer, fadeTexture, NULL, NULL);
        SDL_DestroyTexture(fadeTexture);

        SDL_RenderPresent(manager->sceneManager->renderer);

        // Aumentar a opacidade
        alpha += (255 / (duration / 16)); // Ajuste a taxa de aumento conforme necessário
        if (alpha > 255) alpha = 255;

        SDL_Delay(16); // Esperar um pouco para controlar a taxa de quadros
    }

    // Trocar a cena aqui
    // manager->sceneManager->current = novaCena;

    // Fade out
    while (alpha > 0) {
        SDL_RenderClear(manager->sceneManager->renderer);

        // Renderizar a nova cena
        if (manager->sceneManager->current != NULL) {
            manager->sceneManager->current->Render(manager);
        }

        // Ajustar a opacidade
        SDL_SetSurfaceAlphaMod(fadeSurface, alpha);
        SDL_Texture *fadeTexture = SDL_CreateTextureFromSurface(manager->sceneManager->renderer, fadeSurface);
        SDL_RenderCopy(manager->sceneManager->renderer, fadeTexture, NULL, NULL);
        SDL_DestroyTexture(fadeTexture);

        SDL_RenderPresent(manager->sceneManager->renderer);

        // Diminuir a opacidade
        alpha -= (255 / (duration / 16)); // Ajuste a taxa de diminuição conforme necessário
        if (alpha < 0) alpha = 0;

        SDL_Delay(16); // Esperar um pouco para controlar a taxa de quadros
    }

    SDL_FreeSurface(fadeSurface);
}*/