#include <Scene.h>

static void Scene_AddObj(Scene *scene, Object obj);
static void Scene_RemoveObj(Scene *scene, size_t index);

Scene *Scene_Init()
{
    Scene *scene = malloc(sizeof(Scene));
    scene->AddObj = Scene_AddObj;
    scene->RemoveObj = Scene_RemoveObj;
    scene->objects = NULL;
    scene->objCount = 0;
    scene->Start = NULL;
    scene->Update = NULL;
    scene->Quit = NULL;
    scene->capacity = 0;
    return scene;
}

static void Scene_AddObj(Scene *scene, Object obj)
{

    if (scene->objCount == scene->capacity)
    {
        scene->capacity = (scene->capacity == 0) ? 4 : scene->capacity * 2;
        Object *temp = realloc(scene->objects, sizeof(Object) * scene->capacity);
        if (!temp)
        {
            fprintf(stderr, "Erro ao realocar memória para os objetos\n");
        }
        scene->objects = temp;
    }

    scene->objects[scene->objCount] = obj;
    scene->objCount++;
}

static void Scene_RemoveObj(Scene *scene, size_t index)
{
    scene->objects[index].Free(&scene->objects[index]);

    for (size_t i = index; i < scene->objCount; i++)
    {
        scene->objects[i] = scene->objects[i + 1];
    }

    scene->objCount--;
}

void Scene_Destroy(Scene *scene)
{
    if (scene->objects)
    {
        for (size_t i = 0; i < scene->objCount; i++)
        {
            Object *obj = &scene->objects[i];
            obj->Free(obj);
        }

        free(scene->objects);
    }
    free(scene);
}