#pragma once

typedef struct GameConfig
{
    int difficulty;
    int style;
} GameConfig;

GameConfig *GameConfig_Init();
char *GameConfig_DifficultyString(GameConfig *config);
char *GameConfig_StyleString(GameConfig *config);
