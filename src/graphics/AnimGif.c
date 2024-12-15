#include <AnimGif.h>

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface);
static SDL_Surface *Gif_ConvertFrameToSurface(Object *obj);

void Gif_UpdateFrame(SDL_Renderer *renderer, Object *obj)
{

    Gif_TransformInTexture(renderer, Gif_ConvertFrameToSurface(obj));
}

static SDL_Surface *Gif_ConvertFrameToSurface(Object *obj)
{
    (void)obj;
    return NULL;
}

static SDL_Texture *Gif_TransformInTexture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    (void)renderer;
    (void)surface;
    return NULL;
}