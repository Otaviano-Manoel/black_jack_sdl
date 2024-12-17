#include <Object.h>
#include <math.h>

static void Obj_Create_Rect(Window *window, Object *obj, int x, int y, int width, int height);
static void Obj_Create_Surface(Object *obj, const char *file, int width, int height, SDL_bool isSetColor);
static void Obj_Create_Texture(SDL_Renderer *renderer, Object *obj);
static void Obj_SetColorKey(Object *obj, Uint8 r, Uint8 g, Uint8 b);
static void Obj_Resize(Object *obj, int width, int height);
static SDL_bool hasNewline(const char *text);
static void Obj_SetTag(Object *obj, char tag[MAX_LENGTH_TAG]);

Object *Obj_Init()
{
    Object *obj = SDL_malloc(sizeof(Object));
    obj->layer = 0;
    obj->surface = NULL;
    obj->texture = NULL;
    obj->rect = NULL;
    obj->rectOrigin = NULL;
    obj->gif = NULL;
    obj->text = NULL;
    obj->isHover = SDL_FALSE;
    obj->isButton = SDL_FALSE;
    obj->isVisible = SDL_TRUE;
    obj->opacity = 255;
    obj->SetTag = Obj_SetTag;
    obj->Create_Rect = Obj_Create_Rect;
    obj->Create_Surface = Obj_Create_Surface;
    obj->Create_Texture = Obj_Create_Texture;
    obj->SetColorKey = Obj_SetColorKey;
    obj->OnHover = NULL;
    obj->OnLeave = NULL;
    obj->OnAnimClick = NULL;
    obj->OnClick = NULL;
    obj->LoadAnimatedGIF = NULL;
    return obj;
}

Object *Obj_CreateWithImage(GameManager *manager, const char *file, char *tag, int layer, int x, int y, int width, int height, Uint8 opacity, SDL_bool isSetColor, SDL_bool isButton, void (*OnClick)(GameManager *manager, struct Object *this))
{
    Object *obj = Obj_Init();
    obj->Create_Rect(manager->sceneManager->window, obj, x, y, width, height);
    obj->Create_Surface(obj, GetFilePath(manager, file), width, height, isSetColor);
    obj->Create_Texture(manager->sceneManager->renderer, obj);
    obj->SetTag(obj, tag);
    obj->layer = layer;
    obj->opacity = opacity;
    if (isButton)
    {
        obj->isButton = isButton;
        RegisterEvent(obj);
        obj->OnClick = OnClick;
    }
    return obj;
}

Object *Obj_CreateWithText(GameManager *manager, Object *objDest, SDL_Color textColor, char *writer, char *fileFont, char *tag, int layer, int ptsize, int x, int y, int lineSpace, Uint8 opacity)
{
    Object *obj = objDest;

    if (obj == NULL)
    {
        obj = Obj_Init();
        obj->Create_Rect(manager->sceneManager->window, obj, x, y, 0, 0);
        x = 0;
        y = 0;
    }

    if (obj->text)
        obj->text = Text_Init();

    if (!hasNewline(writer))
        obj->text = Text_CreateWithOneLine(manager, obj, textColor, writer, fileFont, ptsize, x, y);
    else
        obj->text = Text_CreateWithMultiLine(manager, obj, textColor, writer, fileFont, ptsize, x, y, lineSpace);

    obj->SetTag(obj, tag);
    obj->layer = layer;
    obj->opacity = opacity;

    return obj;
}

Object *Obj_CreateWithGif(GameManager *manager, char *file, char *prefix, char *tag, Uint8 opacity, int length, int duplicate, int x, int y, int width, int height, int layer)
{
    Object *obj = Obj_Init();
    Gif_Init(obj, GetFilePath(manager, file), prefix, length, duplicate, width, height);
    obj->Create_Rect(manager->sceneManager->window, obj, x, y, width, height);
    obj->SetTag(obj, tag);
    obj->layer = layer;
    obj->opacity = opacity;
    obj->gif->UpdateFrame(manager->sceneManager->renderer, obj);
    return obj;
}

static SDL_bool hasNewline(const char *text)
{
    return strchr(text, '\n') != NULL;
}

static void Obj_SetTag(Object *obj, char tag[MAX_LENGTH_TAG])
{
    SDL_strlcpy(obj->tag, tag, MAX_LENGTH_TAG);
}

static void Obj_Create_Rect(Window *window, Object *obj, int x, int y, int width, int height)
{
    if (obj->rect == NULL)
        obj->rect = SDL_malloc(sizeof(SDL_Rect));
    obj->rect->x = (int)(((float)x * window->scale) + window->offsetX);
    obj->rect->y = (int)(((float)y * window->scale) + window->offsetY);
    obj->rect->w = (int)((float)width * window->scale);
    obj->rect->h = (int)((float)height * window->scale);
    obj->xEnd = obj->rect->x + obj->rect->w;
    obj->yEnd = obj->rect->y + obj->rect->h;

    if (obj->rectOrigin == NULL)
    {
        obj->rectOrigin = SDL_malloc(sizeof(SDL_Rect));
        obj->rectOrigin->x = x;
        obj->rectOrigin->y = y;
        obj->rectOrigin->w = width;
        obj->rectOrigin->h = height;
    }
}

static void Obj_Create_Surface(Object *obj, const char *file, int width, int height, SDL_bool isSetColor)
{
    if (obj->surface)
    {
        SDL_FreeSurface(obj->surface);
        obj->surface = NULL;
    }

    SDL_Surface *image = SDL_LoadBMP(file);
    if (!image)
    {
        printf("Erro ao carregar imagem: %s\n", SDL_GetError());
        return;
    }

    obj->surface = image;

    if (width != 0 && height != 0)
        Obj_Resize(obj, width, height);
    else
        Obj_Resize(obj, 1, 1);

    if (isSetColor)
        Obj_SetColorKey(obj, 255, 240, 0);

    SDL_FreeSurface(image);
}

static void Obj_Create_Texture(SDL_Renderer *renderer, Object *obj)
{
    if (obj->texture)
    {
        SDL_DestroyTexture(obj->texture);
        obj->texture = NULL;
    }

    obj->texture = SDL_CreateTextureFromSurface(renderer, obj->surface);

    if (!obj->texture)
    {
        printf("Erro ao criar textura: %s\n", SDL_GetError());
        return;
    }
}

static void Obj_SetColorKey(Object *obj, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetColorKey(obj->surface, SDL_TRUE, SDL_MapRGB(obj->surface->format, r, g, b));
}

static void Obj_Resize(Object *obj, int width, int height)
{
    if (!obj->surface)
    {
        printf("Erro: Nenhuma superfície para redimensionar.\n");
        return;
    }

    SDL_Surface *resizedImage = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (resizedImage)
    {
        SDL_BlitScaled(obj->surface, NULL, resizedImage, NULL);
        obj->surface = resizedImage;
    }
    else
    {
        printf("Erro ao criar superfície redimensionada: %s\n", SDL_GetError());
    }
}

void Obj_Free(Object *obj)
{
    SDL_FreeSurface(obj->surface);
    SDL_DestroyTexture(obj->texture);
    SDL_free(obj->rect);
    SDL_free(obj->rectOrigin);
    if (obj->gif)
    {
        Gif_Free(obj->gif);
        if (obj->gif)
            SDL_free(obj->gif);
    }

    if (obj->text)
    {
        Text_Free(obj->text);
        SDL_free(obj->text);
    }
}