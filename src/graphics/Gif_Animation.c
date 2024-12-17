#include <Gif_Animation.h>

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface);
static SDL_Surface *Gif_GetSurfaceFrame(Object *obj);
static void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj);
static SDL_Surface *Gif_CreateSurface(const char *file, int width, int height);

void Gif_Init(Object *obj, char *file, char *prefix, int length, int duplicate, int width, int height)
{
    if (!obj->gif)
        obj->gif = SDL_malloc(sizeof(Gif));

    obj->gif->length = length;
    obj->gif->duplicate = duplicate;
    obj->gif->duplicate_current = 0;
    obj->gif->UpdateFrame = Gif_UpdateFrame;

    for (size_t i = 0; i < 120; i++)
    {
        obj->gif->surfaces[i] = NULL;
    }
    for (int i = 0; i < length; i++)
    {
        char *path = SDL_malloc(sizeof(char) * (strlen(file) + 200));
        snprintf(path, strlen(file) + 200, "%s/%s%d.bmp", file, prefix, i);

        SDL_Surface *surface = Gif_CreateSurface(path, width, height);
        obj->gif->surfaces[i] = surface;
        SDL_SetColorKey(obj->gif->surfaces[i], SDL_TRUE, SDL_MapRGB(obj->gif->surfaces[i]->format, 255, 255, 255));
        SDL_free(path);
    }

    obj->gif->current = 0;
}

static SDL_Surface *Gif_CreateSurface(const char *file, int width, int height)
{
    SDL_Surface *surface = SDL_LoadBMP(file);

    SDL_Surface *resizedImage = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (resizedImage)
    {
        SDL_BlitScaled(surface, NULL, resizedImage, NULL);
    }
    else
    {
        printf("Erro ao criar superfície redimensionada: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    return resizedImage;
}

static void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj)
{
    obj->surface = Gif_GetSurfaceFrame(obj);
    if (obj->texture)
    {
        SDL_DestroyTexture(obj->texture);
    }
    obj->texture = Gif_TransformInTexture(renderer, obj->surface);
}

void Gif_Free(Gif *gif)
{
    gif->surfaces[gif->current - 1] = NULL;
    SDL_FreeSurface(gif->surfaces[gif->current]);
    gif->surfaces[gif->current] = NULL;

    for (int i = 0; i < 120; i++)
    {
        if (gif->surfaces[i])
        {
            SDL_FreeSurface(gif->surfaces[i]);
            gif->surfaces[i] = NULL;
        }
    }
}

static SDL_Surface *Gif_GetSurfaceFrame(Object *obj)
{
    SDL_Surface *frame = obj->gif->surfaces[obj->gif->current];

    if (++obj->gif->current >= obj->gif->length)
    {
        obj->gif->current = 0;
    }

    return frame;
}

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return SDL_CreateTextureFromSurface(renderer, surface);
}