#pragma once

#include <Game_Manager.h>

typedef enum
{
    DIFFICULTY_EASY = 0,
    DIFFICULTY_MEDIUM,
    DIFFICULTY_HARD
} Difficulty;

typedef enum
{
    STYLE_CLASSIC = 0,
    STYLE_MODERN
} Style;

typedef struct GameConfig
{
    Difficulty difficulty;
    Style style;
} GameConfig;

GameConfig *GameConfig_Init();
char *GameConfig_DifficultyString(GameConfig *config);
char *GameConfig_StyleString(GameConfig *config);
