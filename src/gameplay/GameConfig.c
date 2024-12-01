#include <GameConfig.h>
#include <GameManager.h>

GameConfig *GameConfig_Init()
{
    GameConfig *config = malloc(sizeof(GameConfig));
    config->difficulty = 0;
    config->style = 0;
    return config;
}

char *GameConfig_DifficultyString(GameConfig *config)
{
    switch (config->difficulty)
    {
    case 0:
        return "Easy";
    case 1:
        return "Medium";
    case 2:
        return "Hard";
    }

    return "Unknown";
}

char *GameConfig_StyleString(GameConfig *config)
{
    switch (config->style)
    {
    case 0:
        return "Classic";
    case 1:
        return "Modern";
    }

    return "Unknown";
}