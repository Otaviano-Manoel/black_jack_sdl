#include <Object.h>
#include <math.h>

static void Obj_SetImage(SDL_Renderer *renderer, Object *obj, const char *file, int width, int height);
static void Obj_Resize(Object *obj, int width, int height);
static void Obj_ResizeRect(Object *obj, int x, int y, int width, int height);
static void Obj_SetColorKey(Object *obj, Uint8 r, Uint8 g, Uint8 b);
static void Obj_InitFull(SDL_Renderer *renderer, Object *obj,
                         int x, int y, int width, int height, const char *file,
                         Uint8 r, Uint8 g, Uint8 b);

Object Obj_Init()
{
    Object obj;
    obj.text = Text_Init();
    obj.SetImage = Obj_SetImage;
    obj.ResizeRect = Obj_ResizeRect;
    obj.SetColorKey = Obj_SetColorKey;
    obj.InitFull = Obj_InitFull;
    obj.OnClick = NULL;
    obj.OnHover = NULL;
    obj.OnLeave = NULL;
    obj.OnAnimClick = NULL;
    obj.isHover = SDL_FALSE;
    obj.isButton = SDL_FALSE;
    obj.width = 0;
    obj.height = 0;
    obj.xEnd = 0;
    obj.yEnd = 0;
    obj.opacity = 255;
    obj.surface = NULL;
    obj.texture = NULL;
    obj.rect = NULL;
    obj.layer = 0;
    return obj;
}

static void Obj_InitFull(SDL_Renderer *renderer, Object *obj,
                         int x, int y, int width, int height, const char *file,
                         Uint8 r, Uint8 g, Uint8 b)
{
    if (!renderer || !obj || !file || width <= 0 || height <= 0)
    {
        printf("Parâmetros inválidos em Obj_Create.\n");
        return;
    }

    Obj_ResizeRect(obj, x, y, width, height);
    Obj_SetImage(renderer, obj, file, width, height);
    Obj_SetColorKey(obj, r, g, b);
}

static void Obj_ResizeRect(Object *obj, int x, int y, int width, int height)
{
    if (obj->rect)
        free(obj->rect);
    obj->rect = malloc(sizeof(SDL_Rect));
    obj->rect->x = x;
    obj->rect->y = y;
    obj->rect->w = width;
    obj->rect->h = height;
    obj->xEnd = x + width;
    obj->yEnd = y + height;

    obj->width = width;
    obj->height = height;
}

static void Obj_SetImage(SDL_Renderer *renderer, struct Object *obj, const char *file, int width, int height)
{
    SDL_Surface *image = SDL_LoadBMP(file);
    if (!image)
    {
        printf("Erro ao carregar imagem: %s\n", SDL_GetError());
        return;
    }

    obj->surface = image;

    if (width != 0 && height != 0)
    {
        Obj_Resize(obj, width, height);
    }

    // SDL_SetColorKey(obj->surface, SDL_TRUE, SDL_MapRGB(obj->surface->format, 0, 0, 0));

    obj->texture = SDL_CreateTextureFromSurface(renderer, obj->surface);

    if (!obj->texture)
    {
        printf("Erro ao criar textura: %s\n", SDL_GetError());
        return;
    }

    if (obj->texture)
        SDL_FreeSurface(obj->surface);
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
        SDL_FreeSurface(obj->surface);
        obj->surface = resizedImage;
    }
    else
    {
        printf("Erro ao criar superfície redimensionada: %s\n", SDL_GetError());
    }
}

static void Obj_Destroy(obj)
{
}