#include <Text.h>

static void Text_SetFont(Window *window, Text *text, char *file, int ptsize);
static void Text_SetText(SDL_Renderer *renderer, Text *text, SDL_Color textColor, char *writer, int line);
static void Text_SetTexture(SDL_Renderer *renderer, Text *text, int line);
static void Text_SetPosition(Window *window, Object *obj, Text *text, int x, int y, int line);

Text *Text_Init()
{
    Text *text = SDL_malloc(sizeof(Text));
    text->font = NULL;
    for (size_t i = 0; i < 50; i++)
    {
        text->textRect[i] = NULL;
        text->textRectOrigin[i] = NULL;
        text->textSurface[i] = NULL;
        text->textTexture[i] = NULL;
        text->text[i] = NULL;
    }
    text->isTextLoaded = SDL_FALSE;
    text->file = "\0";
    text->lineSpace = 0;
    text->lines = 0;
    text->SetText = Text_SetText;
    text->SetFont = Text_SetFont;
    text->SetPosition = Text_SetPosition;
    return text;
}

Text *Text_CreateWithOneLine(GameManager *manager, Object *obj, SDL_Color textColor, char *writer, char *fileFont, int ptsize, int x, int y)
{
    Text *text = Text_Init();
    text->SetFont(manager->sceneManager->window, text, GetFilePath(manager, fileFont), ptsize);
    text->SetText(manager->sceneManager->renderer, text, textColor, writer, 0);
    text->SetPosition(manager->sceneManager->window, obj, text, x, y, 0);
    text->lines = 1;
    text->isTextLoaded = SDL_TRUE;
    text->file = SDL_malloc(sizeof(char) * (SDL_strlen(fileFont) + 1));
    SDL_strlcpy(text->file, fileFont, SDL_strlen(fileFont) + 1);
    return text;
}

Text *Text_CreateWithMultiLine(GameManager *manager, Object *obj, SDL_Color textColor, char *writer, char *fileFont, int ptsize, int x, int y, int lineSpace)
{
    Text *text = Text_Init();
    text->SetFont(manager->sceneManager->window, text, GetFilePath(manager, fileFont), ptsize);
    text->file = SDL_malloc(sizeof(char) * (SDL_strlen(fileFont) + 1));
    SDL_strlcpy(text->file, fileFont, SDL_strlen(fileFont) + 1);
    text->lineSpace = lineSpace;

    char *textCopy = SDL_strdup(writer);
    const char *delimiters = "\n";
    char *saveptr;
    char *token;
    int line = 0;

    token = SDL_strtokr(textCopy, delimiters, &saveptr);

    while (token != NULL)
    {
        text->SetText(manager->sceneManager->renderer, text, textColor, token, line);
        text->SetPosition(manager->sceneManager->window, obj, text, x, y + (line * lineSpace), line);
        line++;
        token = SDL_strtokr(NULL, delimiters, &saveptr);
    }

    text->ptSize = ptsize;
    text->lines = line;
    text->isTextLoaded = SDL_TRUE;

    SDL_free(textCopy);
    return text;
}

static void Text_SetFont(Window *window, Text *text, char *file, int ptsize)
{
    int scaledSize = (int)((float)ptsize * window->scale);

    if (scaledSize < 8)
        scaledSize = 8;

    if (scaledSize > 72)
        scaledSize = 72;

    text->font = TTF_OpenFont(file, scaledSize);

    if (text->font == NULL)
        SDL_Log("Erro ao carregar fonte: %s", TTF_GetError());
}

static void Text_SetText(SDL_Renderer *renderer, Text *text, SDL_Color textColor, char *writer, int line)
{
    if (text->textSurface[line] != NULL)
    {
        SDL_FreeSurface(text->textSurface[line]);
        text->textSurface[line] = NULL;
    }
    text->text[line] = SDL_malloc(SDL_strlen(writer) + 1);
    text->color = textColor;

    SDL_strlcpy(text->text[line], writer, SDL_strlen(writer) + 1);

    text->textSurface[line] = TTF_RenderText_Blended(text->font, text->text[line], textColor);

    if (text->textSurface[line] == NULL)
    {
        SDL_Log("Erro ao renderizar texto: %s", TTF_GetError());
        return;
    }

    Text_SetTexture(renderer, text, line);
}

static void Text_SetTexture(SDL_Renderer *renderer, Text *text, int line)
{
    if (text->textTexture[line])
    {
        SDL_DestroyTexture(text->textTexture[line]);
        text->textTexture[line] = NULL;
    }

    text->textTexture[line] = SDL_CreateTextureFromSurface(renderer, text->textSurface[line]);
    if (text->textTexture[line] == NULL)
    {
        SDL_Log("Erro ao criar textura do texto: %s", SDL_GetError());
        return;
    }
}

static void Text_SetPosition(Window *window, Object *obj, Text *text, int x, int y, int line)
{
    if (text->textRect[line] == NULL)
        text->textRect[line] = SDL_malloc(sizeof(SDL_Rect));
    text->textRect[line]->x = (int)(((float)(obj->rectOrigin->x + x) * window->scale) + (window->offsetX));
    text->textRect[line]->y = (int)(((float)(obj->rectOrigin->y + y) * window->scale) + (window->offsetY));
    text->textRect[line]->w = text->textSurface[line]->w;
    text->textRect[line]->h = text->textSurface[line]->h;

    if (text->textRectOrigin[line] == NULL)
    {
        text->textRectOrigin[line] = SDL_malloc(sizeof(SDL_Rect));
        text->textRectOrigin[line]->x = x;
        text->textRectOrigin[line]->y = y;
        text->textRectOrigin[line]->w = text->textSurface[line]->w;
        text->textRectOrigin[line]->h = text->textSurface[line]->h;
    }
}

void Text_Free(Text *text)
{
    if (text->font != NULL)
        TTF_CloseFont(text->font);
    for (int i = 0; i < 50; i++)
    {
        if (text->textSurface[i])
            SDL_FreeSurface(text->textSurface[i]);

        if (text->textTexture[i])
            SDL_DestroyTexture(text->textTexture[i]);

        if (text->textRect[i])
            SDL_free(text->textRect[i]);

        if (text->textRectOrigin[i])
            SDL_free(text->textRectOrigin[i]);

        if (text->text[i])
            SDL_free(text->text[i]);
    }

    SDL_free(text->file);
}