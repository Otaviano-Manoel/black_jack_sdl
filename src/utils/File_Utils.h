#pragma once

#include <Game_Manager.h>

char *GetPath(size_t size);
char *BuildFilePath(const char *basePath, const char *fileName);
char *GetFilePath(GameManager *manager, const char *fileName);