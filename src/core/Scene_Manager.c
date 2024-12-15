#include <Scene_Manager.h>
#include <Fade_Transition.h>

static void SceneManager_init_SDL(SceneManager *this);
static void SceneManager_ChangeScene(GameManager *manager, Scene *next);
static void SceneManager_Start(GameManager *);
static void SceneManager_Update(GameManager *);
static void SceneManager_Quit(GameManager *);
static void SceneManager_Init_SDL_Mixer(GameManager *this);

SceneManager *SceneManager_Init()
{
    SceneManager *sceneManager = malloc(sizeof(SceneManager));
    sceneManager->event = (SDL_Event *)malloc(sizeof(SDL_Event));
    sceneManager->ChangeScene = SceneManager_ChangeScene;
    sceneManager->Start = SceneManager_Start;
    sceneManager->Update = SceneManager_Update;
    sceneManager->Quit = SceneManager_Quit;
    sceneManager->Init_SDL_Mixer = SceneManager_Init_SDL_Mixer;
    SceneManager_init_SDL(sceneManager);

    return sceneManager;
}

void Scene_Manager_Free(SceneManager *this)
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window->window);
    Mix_FreeMusic(this->mix);
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
    Scene_Free(manager->sceneManager->current);
    SDL_free(manager->sceneManager->current);
}

static void SceneManager_init_SDL(SceneManager *this)
{
    this->window = Window_Init();

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