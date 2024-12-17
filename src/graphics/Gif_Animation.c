#include <Gif_Animation.h>

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface);
static SDL_Surface *Gif_GetSurfaceFrame(Object *obj);

void Gif_Init(Object *obj, char *file, int length, int duplicate, char *prefix)
{
    if (obj->gif == NULL)
        obj->gif = SDL_malloc(sizeof(Gif));

    obj->gif->length = length * duplicate;

    int index = 0;
    for (int i = 0; i < length; i++)
    {
        char *path = SDL_malloc(sizeof(char) * (strlen(file) + 200));
        snprintf(path, strlen(file) + 200, "%s/%s%d.bmp", file, prefix, i);

        SDL_Surface *surface = SDL_LoadBMP(path);
        SDL_free(path);
        for (int j = 0; j < duplicate; j++)
        {
            obj->gif->surfaces[index++] = surface;
        }
    }

    obj->gif->current = 0;
}

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj)
{
    obj->surface = Gif_GetSurfaceFrame(obj);
    obj->SetColorKey(obj, 255, 255, 255);
    obj->texture = Gif_TransformInTexture(renderer, obj->surface);
}

void Gif_Free(Gif *gif)
{
    for (size_t i = 0; i < 120; i++)
    {
        if (gif->surfaces[i] != NULL)
        {
            SDL_free(gif->surfaces[i]);
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