#include <Object.h>
#include <math.h>

static void Obj_SetImage(SDL_Renderer *renderer, Object *obj, const char *file, int width, int height);
static void Obj_Resize(Object *obj, int width, int height);
static void Obj_ResizeRect(Object *obj, int x, int y, int width, int height);

Object Obj_Init()
{
    Object obj;
    obj.text = Text_Init();
    obj.Obj_SetImage = Obj_SetImage;
    obj.Obj_ResizeRect = Obj_ResizeRect;
    obj.isHover = SDL_FALSE;
    obj.isButton = SDL_FALSE;
    obj.opacity = 255;
    return obj;
}

static void Obj_ResizeRect(Object *obj, int x, int y, int width, int height)
{
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

    SDL_SetColorKey(obj->surface, SDL_TRUE, SDL_MapRGB(obj->surface->format, 0, 0, 0));

    obj->texture = SDL_CreateTextureFromSurface(renderer, obj->surface);

    if (!obj->texture)
    {
        printf("Erro ao criar textura: %s\n", SDL_GetError());
        return;
    }

    obj->width = width;
    obj->height = height;
    SDL_FreeSurface(obj->surface);
}

static void Obj_Resize(Object *obj, int width, int height)
{
    if (!obj->surface)
    {
        printf("Erro: Nenhuma superfície para redimensionar.\n");
        return;
    }

    SDL_Surface *resizedImage = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (!resizedImage)
    {
        printf("Erro ao criar superfície redimensionada: %s\n", SDL_GetError());
        return;
    }
    SDL_BlitScaled(obj->surface, NULL, resizedImage, NULL);
    SDL_FreeSurface(obj->surface);
    obj->surface = resizedImage;
}