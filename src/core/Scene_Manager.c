#include <Scene_Manager.h>

static void SceneManager_init_SDL(GameManager *this);
static void SceneManager_ChangeScene(GameManager *manager, Scene *next);
static void SceneManager_Start(GameManager *);
static void SceneManager_Update(GameManager *);
static void SceneManager_Quit(GameManager *);
static void SceneManager_Init_SDL_Mixer(GameManager *this);
static void SceneManager_Init_SDL_Renderer(SceneManager *this);

void SceneManager_Init(GameManager *this)
{
    SceneManager *sceneManager = SDL_malloc(sizeof(SceneManager));

    sceneManager->event = (SDL_Event *)SDL_malloc(sizeof(SDL_Event));
    sceneManager->ChangeScene = SceneManager_ChangeScene;
    sceneManager->Start = SceneManager_Start;
    sceneManager->Update = SceneManager_Update;
    sceneManager->Quit = SceneManager_Quit;
    sceneManager->isCurrentSet = SDL_FALSE;
    sceneManager->layerCurrent = 0;
    sceneManager->current = NULL;

    this->sceneManager = sceneManager;

    SceneManager_init_SDL(this);
}

void Scene_Manager_Free(SceneManager *this)
{
    SDL_DestroyRenderer(this->renderer);
    SDL_free(this->event);
    Mix_FreeMusic(this->mix);
    SDL_free(this->current);
    Window_Free(this->window);
    SDL_free(this->window);
    Mix_CloseAudio();
}

static void SceneManager_ChangeScene(GameManager *manager, Scene *next)
{
    Fade_Transition(manager, next);
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
    manager->sceneManager->current->Update(manager);
    RenderObjectsInScene(manager);
    PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window->window);
    Event_Wait(manager);
}

static void SceneManager_Quit(GameManager *manager)
{
    SDL_free(manager->sceneManager->current);
}

static void SceneManager_init_SDL(GameManager *this)
{
    this->sceneManager->window = Window_Init();
    SceneManager_Init_SDL_Renderer(this->sceneManager);
    SceneManager_Init_SDL_Mixer(this);
}

static void SceneManager_Init_SDL_Renderer(SceneManager *this)
{
    this->renderer = SDL_CreateRenderer(this->window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!this->renderer)
    {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
    }

    if (TTF_Init() == -1)
    {
        SDL_Log("Erro ao inicializar SDL_ttf: %s", TTF_GetError());
    }
}

static void SceneManager_Init_SDL_Mixer(GameManager *this)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Erro ao inicializar SDL_mixer: %s\n", Mix_GetError());
        return;
    }

    this->sceneManager->mix = Mix_LoadMUS(BuildFilePath(this->assets, "mix_back.mp3"));
    if (!this->sceneManager->mix)
    {
        printf("Erro ao carregar música: %s\n", Mix_GetError());
        return;
    }

    if (Mix_PlayMusic(this->sceneManager->mix, -1) == -1)
    { // -1 para repetir indefinidamente
        printf("Erro ao reproduzir música: %s\n", Mix_GetError());
        return;
    }
}