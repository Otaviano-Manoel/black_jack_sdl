#pragma once

#include <GameManager.h>

void RegisterEvent(Object *this, void (*OnHover)(GameManager *manager, struct Object *this), void (*OnExit)(GameManager *manager, struct Object *this));