#include <Gif_Animation.h>

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface);
static SDL_Surface *Gif_GetSurfaceFrame(Object *obj);

void Create_Gif(Object *obj, char *file, int length, char *prefix)
{
    if (obj->gif == NULL)
        obj->gif = SDL_malloc(sizeof(Gif));

    obj->gif->length = length;

    for (int i = 0; i < length; i++)
    {
        char *temp = SDL_malloc(sizeof(char) * (strlen(file) + 50));
        snprintf(temp, 1024, "%s/%s%d.bmp", file, prefix, i);
        SDL_Surface *surface = SDL_LoadBMP(temp);
        obj->gif->surfaces[i] = surface;
    }

    obj->gif->current = 0;
}

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj)
{
    obj->surface = Gif_GetSurfaceFrame(obj);
    obj->SetColorKey(obj, 255, 255, 255);
    obj->texture = Gif_TransformInTexture(renderer, obj->surface);
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