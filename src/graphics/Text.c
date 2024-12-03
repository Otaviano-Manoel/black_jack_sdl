#include <Text.h>

static void Text_SetFont(Text *text, char *file, int ptsize);
static void Text_SetText(SDL_Renderer *renderer, Text *text, char *writer, SDL_Color textColor);
static void Text_SetTexture(SDL_Renderer *renderer, Text *text);
static void Text_SetPosition(Text *text, int x, int y);
static void Text_Free(Text *text);
static void Text_InitFull(SDL_Renderer *renderer, Text *text, char *file, int ptsize, char *writer, SDL_Color textColor, int x, int y);

Text *Text_Init()
{
    Text *text = malloc(sizeof(Text));
    text->font = NULL;
    text->textSurface = NULL;
    text->textTexture = NULL;
    text->textRect = malloc(sizeof(SDL_Rect));

    text->InitFull = Text_InitFull;
    text->SetText = Text_SetText;
    text->SetFont = Text_SetFont;
    text->SetPosition = Text_SetPosition;
    text->Destroy = Text_Free;

    text->isTextLoaded = SDL_FALSE;
    text->text = NULL;
    return text;
}

static void Text_InitFull(SDL_Renderer *renderer, Text *text, char *file, int ptsize, char *writer, SDL_Color textColor, int x, int y)
{
    text->isTextLoaded = SDL_TRUE;
    Text_SetFont(text, file, ptsize);
    Text_SetText(renderer, text, writer, textColor);
    Text_SetPosition(text, x, y);
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

static void Text_SetText(SDL_Renderer *renderer, Text *text, char *writer, SDL_Color textColor)
{
    if (text->text == NULL)
        text->text = malloc(256);

    SDL_strlcpy(text->text, writer, 256);
    text->textSurface = TTF_RenderText_Blended(text->font, text->text, textColor);
    if (text->textSurface == NULL)
    {
        SDL_Log("Erro ao renderizar texto: %s", TTF_GetError());
        return;
    }

    Text_SetTexture(renderer, text);
}

static void Text_SetTexture(SDL_Renderer *renderer, Text *text)
{
    text->textTexture = SDL_CreateTextureFromSurface(renderer, text->textSurface);
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

void Text_Free(Text *text)
{
    if (text->textTexture)
    {
        SDL_DestroyTexture(text->textTexture);
        text->textTexture = NULL;
    }

    if (text->textSurface)
    {
        SDL_FreeSurface(text->textSurface);
        text->textSurface = NULL;
    }

    if (text->textSurface)
    {
        SDL_free(text->textSurface);
        text->textSurface = NULL;
    }
}