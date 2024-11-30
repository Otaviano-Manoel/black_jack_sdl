#include <Text.h>

static void Text_SetFont(Text *text, char *file, int ptsize);
static void Text_SetColo(GameManager *manager, Text *text, char *writer, SDL_Color textColor);
static void Text_SetTexture(GameManager *manager, Text *text);
static void Text_SetPosition(Text *text, int x, int y);

Text *Text_Init()
{
    Text *text = malloc(sizeof(Text));
    text->font = malloc(sizeof(TTF_Font *));
    text->textRect = malloc(sizeof(SDL_Rect));
    text->textSurface = malloc(sizeof(SDL_Surface));

    text->SetColor = Text_SetColo;
    text->SetFont = Text_SetFont;
    text->SetPosition = Text_SetPosition;
    return text;
}

static void Text_SetFont(Text *text, char *file, int ptsize)
{
    text->font = TTF_OpenFont(file, ptsize);
    if (text->font == NULL)
    {
        SDL_Log("Erro ao carregar fonte: %s", TTF_GetError());
        return;
    }
}

static void Text_SetColo(GameManager *manager, Text *text, char *writer, SDL_Color textColor)
{
    text->textSurface = TTF_RenderText_Blended(text->font, writer, textColor);
    if (text->textSurface == NULL)
    {
        SDL_Log("Erro ao renderizar texto: %s", TTF_GetError());
        return;
    }

    Text_SetTexture(manager, text);
}

static void Text_SetTexture(GameManager *manager, Text *text)
{
    text->textTexture = SDL_CreateTextureFromSurface(manager->sceneManager->renderer, text->textSurface);
    if (text->textTexture == NULL)
    {
        SDL_Log("Erro ao criar textura do texto: %s", SDL_GetError());
        return;
    }

    text->textRect->w = text->textSurface->w;
    text->textRect->h = text->textSurface->h;
}

void Text_SetPosition(Text *text, int x, int y)
{
    text->textRect->x = x;
    text->textRect->y = y;
}