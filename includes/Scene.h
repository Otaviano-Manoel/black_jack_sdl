#pragma once

#include <GameManager.h>

typedef struct GameManager GameManager;

typedef struct Scene
{
    struct Object *objects;
    size_t objCount;

    void (*AddObj)(struct Scene *, struct Object);
    void (*Start)(GameManager *);
    void (*Update)(GameManager *);
    void (*Quit)(GameManager *);
} Scene;

Scene *Scene_Init();