#include <Scene.h>

static void Scene_AddObj(Scene *scene, Object *obj);
static void Scene_RemoveObj(Scene *scene, size_t index);

Scene *Scene_Init()
{
    Scene *scene = SDL_malloc(sizeof(Scene));
    scene->objects = NULL;
    scene->objCount = 0;
    scene->capacity = 0;
    scene->AddObj = Scene_AddObj;
    scene->RemoveObj = Scene_RemoveObj;
    scene->Free = Scene_Free;
    scene->Start = NULL;
    scene->Update = NULL;
    scene->Quit = NULL;
    return scene;
}

Object *Scene_FindTag(Scene *scene, char *tag)
{
    for (size_t i = 0; i < scene->objCount; i++)
    {
        if (SDL_strcasecmp(tag, scene->objects[i]->tag) == 0)
        {
            return scene->objects[i];
        }
    }
    return NULL;
}

static void Scene_AddObj(Scene *scene, Object *obj)
{
    if (scene->objCount == scene->capacity)
    {
        scene->capacity = (scene->capacity == 0) ? 4 : scene->capacity * 2;
        Object **temp = NULL;
        if (scene->capacity == 0)
            temp = malloc(sizeof(Object *) * scene->capacity);
        else
            temp = realloc(scene->objects, sizeof(Object *) * scene->capacity);

        if (!temp)
        {
            fprintf(stderr, "Erro ao realocar memória para os objetos\n");
        }
        scene->objects = temp;

        for (size_t i = scene->objCount; i < scene->capacity; i++)
        {
            scene->objects[i] = NULL;
        }
    }

    scene->objects[scene->objCount] = obj;
    scene->objCount++;
}

static void Scene_RemoveObj(Scene *scene, size_t index)
{
    Obj_Free(scene->objects[index]);

    for (size_t i = index; i < scene->objCount; i++)
    {
        scene->objects[i] = scene->objects[i + 1];
    }

    scene->objCount--;
}

void Scene_Free(Scene *scene)
{
    if (scene->objects)
    {
        for (size_t i = 0; i < scene->capacity; i++)
        {
            Object *obj = scene->objects[i];
            if (obj)
                Obj_Free(obj);
        }

        free(scene->objects);
    }
}