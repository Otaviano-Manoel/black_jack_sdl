#include <Scene_Manager.h>
#include <Fade_Transition.h>

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

void Scene_Manager_Free(SceneManager *this)
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
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
    PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window);
    Event_Wait(manager);
}

static void SceneManager_Quit(GameManager *manager)
{
    Scene_Free(manager->sceneManager->current);
    SDL_free(manager->sceneManager->current);
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