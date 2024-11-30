#include <Setting.h>
#include <ObjectEvent.h>

void Setting_Init(GameManager *gameManager)
{
    gameManager->sceneManager->layerCurrent = 3;
    Object obj;
    SDL_Renderer *renderer = gameManager->sceneManager->renderer;

    // Obj
    obj = Obj_Init();
    obj.layer = 2;
    obj.opacity = 128;
    obj.Obj_ResizeRect(&obj, 0, 0, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    obj.Obj_SetImage(renderer, &obj, GetFile(gameManager, "setting.bmp"), MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW);
    SDL_strlcpy(obj.tag, TAG_BACKGROUND, sizeof(obj.tag));
    RegisterEvent(&obj, NULL, NULL);
    gameManager->sceneManager->current->AddObj(gameManager->sceneManager->current, obj);
}