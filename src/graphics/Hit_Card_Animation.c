#include <Hit_Card_Animation.h>

static void Hit_Card_Animation_Render(GameManager *manager, Object *obj_Anim, int xEnd, int yEnd, int speed);
static Object Hit_CreateObjAnimated(GameManager *manager, Card *card, Object *src, Object *dest, char *tag);

void Hit_Card_Animation_Run(GameManager *manager, Card *card, SDL_bool isP1)
{
    char *tag = isP1 ? "c-p1" : "c-p2";

    Scene *current = manager->sceneManager->current;

    Object *src = Scene_FindTag(current, "deck");

    Object *dest = Scene_FindTag(current, tag);
    dest->SetTag(dest, "none");

    Object obj_Card = Hit_CreateObjAnimated(manager, card, src, dest, tag);

    Hit_Card_Animation_Render(manager, &obj_Card, dest->rect->x + (obj_Card.rect->h / 2), dest->rect->y, 8);

    obj_Card.ResizeRect(&obj_Card, obj_Card.rect->x, obj_Card.rect->y, obj_Card.rect->w, obj_Card.rect->h);

    manager->sceneManager->current->AddObj(manager->sceneManager->current, obj_Card);
}

static void Hit_Card_Animation_Render(GameManager *manager, Object *obj_Anim, int xEnd, int yEnd, int speed)
{
    while (obj_Anim->rect->x != xEnd || obj_Anim->rect->y != yEnd)
    {
        ClearRender(manager->sceneManager->renderer);
        RenderObjectsInScene(manager);
        RenderObject(manager->sceneManager->renderer, obj_Anim);
        PresentRenderer(manager->sceneManager->renderer, manager->sceneManager->window);

        // Movimento suave no eixo X
        if (obj_Anim->rect->x > xEnd)
            obj_Anim->rect->x = (obj_Anim->rect->x - speed < xEnd) ? xEnd : obj_Anim->rect->x - speed;

        // Movimento suave no eixo Y
        if (obj_Anim->rect->y < yEnd)
            obj_Anim->rect->y = (obj_Anim->rect->y + speed > yEnd) ? yEnd : obj_Anim->rect->y + speed;
        else if (obj_Anim->rect->y > yEnd)
            obj_Anim->rect->y = (obj_Anim->rect->y - speed < yEnd) ? yEnd : obj_Anim->rect->y - speed;

        SDL_Delay(4);
    }
}

static Object Hit_CreateObjAnimated(GameManager *manager, Card *card, Object *src, Object *dest, char *tag)
{
    Object obj = Obj_Init();
    obj.InitFull(manager->sceneManager->renderer, &obj, src->rect->x, src->rect->y, dest->rect->w, dest->rect->h,
                 BuildFilePath(manager->assets, Card_GetNameFileBMP(card)), 0, 0, 0, SDL_FALSE, 255, 1, SDL_FALSE, NULL, NULL, NULL);
    obj.SetTag(&obj, tag);

    return obj;
}