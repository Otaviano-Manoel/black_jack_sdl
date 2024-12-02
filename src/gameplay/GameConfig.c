#include <GameConfig.h>

GameConfig *GameConfig_Init()
{
    GameConfig *config = malloc(sizeof(GameConfig));
    config->difficulty = DIFFICULTY_MEDIUM;
    config->style = STYLE_CLASSIC;
    return config;
}

char *GameConfig_DifficultyString(GameConfig *config)
{
    switch (config->difficulty)
    {
    case DIFFICULTY_EASY:
        return "Easy";
    case DIFFICULTY_MEDIUM:
        return "Medium";
    case DIFFICULTY_HARD:
        return "Hard";
    default:
        return "Unknown";
    }
}

char *GameConfig_StyleString(GameConfig *config)
{
    switch (config->style)
    {
    case STYLE_CLASSIC:
        return "Classic";
    case STYLE_MODERN:
        return "Modern";
    default:
        return "Unknown";
    }
}