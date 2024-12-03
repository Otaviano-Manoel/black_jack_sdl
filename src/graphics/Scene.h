#pragma once

#include <Game_Manager.h>

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
    void (*Free)(Scene *scene);
} Scene;

Scene *Scene_Init();
Object *Scene_FindTag(Scene *scene, char tag[32]);
void Scene_Free(Scene *scene);