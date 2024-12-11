#include <Window.h>

Window *Window_Init()
{
    Window *window = SDL_malloc(sizeof(Window));
    window->window = SDL_CreateWindow("21 Master", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_GetWindowSize(window->window, &window->screenWidth, &window->screenHeight);
    window->scaleX = (float)window->screenWidth / 1200.0f;
    window->scaleY = (float)window->screenHeight / 720.0f;
    window->scale = (window->scaleX < window->scaleY) ? window->scaleX : window->scaleY;
    window->offsetX = ((float)window->screenWidth - (1200 * window->scale)) / 2;
    window->offsetY = ((float)window->screenHeight - (720 * window->scale)) / 2;
    return window;
}