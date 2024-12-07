#include <Game_Config.h>

static void GameConfig_Difficulty_Change(GameConfig *config);
static void GameConfig_Style_Change(GameConfig *config);

GameConfig *GameConfig_Init()
{
    GameConfig *config = malloc(sizeof(GameConfig));
    config->difficulty = DIFFICULTY_EASY;
    config->style = STYLE_CLASSIC;
    config->Difficulty_Change = GameConfig_Difficulty_Change;
    config->Style_Change = GameConfig_Style_Change;
    return config;
}

static void GameConfig_Style_Change(GameConfig *config)
{
    config->style = config->style == STYLE_CLASSIC ? STYLE_MODERN : STYLE_CLASSIC;
}

static void GameConfig_Difficulty_Change(GameConfig *config)
{
    if (config->difficulty == DIFFICULTY_HARD)
        config->difficulty = DIFFICULTY_EASY;
    else
        config->difficulty++;
}

char *GameConfig_Difficulty_String(GameConfig *config)
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

char *GameConfig_Style_String(GameConfig *config)
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