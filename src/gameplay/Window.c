#include <Window.h>

static void Window_UpdateScreen(Window *this);

Window *Window_Init()
{
    Window *window = SDL_malloc(sizeof(Window));
    window->window = SDL_CreateWindow("21 Master", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, SDL_WINDOW_SHOWN);
    window->UpdateScreen = Window_UpdateScreen;
    Window_UpdateScreen(window);
    window->isFullScreen = SDL_FALSE;
    return window;
}

void Window_Free(Window *this)
{
    SDL_DestroyWindow(this->window);
}

static void Window_UpdateScreen(Window *this)
{
    SDL_GetWindowSize(this->window, &this->screenWidth, &this->screenHeight);
    this->scaleX = (float)this->screenWidth / MAX_WIDTH_WINDOW;
    this->scaleY = (float)this->screenHeight / MAX_HEIGHT_WINDOW;
    this->scale = (this->scaleX < this->scaleY) ? this->scaleX : this->scaleY;
    this->offsetX = ((float)this->screenWidth - (MAX_WIDTH_WINDOW * this->scale)) / 2;
    this->offsetY = ((float)this->screenHeight - (MAX_HEIGHT_WINDOW * this->scale)) / 2;
}