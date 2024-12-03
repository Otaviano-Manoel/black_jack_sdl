#pragma once

#include <GameManager.h>

typedef struct Scene
{
    struct Object *objects;
    size_t objCount;
    size_t capacity;

    void (*AddObj)(struct Scene *, struct Object);
    void (*Start)(GameManager *);
    void (*Update)(GameManager *);
    void (*Quit)(GameManager *);
    void (*RemoveObj)(struct Scene *scene, size_t index);
} Scene;

Scene *Scene_Init();
void Scene_Destroy(Scene *scene);