#include <Scene.h>

static void Scene_AddObj(Scene *scene, Object obj);

Scene *Scene_Init()
{
    Scene *scene = malloc(sizeof(Scene));
    scene->AddObj = Scene_AddObj;
    return scene;
}

static void Scene_AddObj(Scene *scene, Object obj)
{
    if (scene->objCount == 0)
    {
        // Aloca espaço para o primeiro objeto
        scene->objects = malloc(sizeof(Object));
        if (!scene->objects)
        {
            fprintf(stderr, "Erro ao alocar memória para o objeto\n");
            return;
        }
    }
    else
    {
        // Realoca memória para armazenar mais um objeto
        Object *temp = realloc(scene->objects, sizeof(Object) * (scene->objCount + 1));
        if (!temp)
        {
            fprintf(stderr, "Erro ao realocar memória para os objetos\n");
            return;
        }
        scene->objects = temp;
    }

    // Adiciona o novo objeto no final do array
    scene->objects[scene->objCount] = obj;
    scene->objCount++;
}