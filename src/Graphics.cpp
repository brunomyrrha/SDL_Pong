#include "Graphics.h"

Graphics::Graphics(bool& init)
{
    init = InitSDL();
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool Graphics::InitSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
        if (!window)
        {
            LOG("Failed to create window.")
            return false;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer)
        {
            LOG("Failed to create renderer")
            return false;
        }
    }
    return true;
}

void Graphics::RenderScene()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    for(int i = 0; i < RenderQueueSize; i++)
    {
        SDL_SetRenderDrawColor(renderer, RenderQueueElements[i].color[0],
                                        RenderQueueElements[i].color[1],
                                        RenderQueueElements[i].color[2],
                                        SDL_ALPHA_OPAQUE);
        SDL_Rect frame = { RenderQueueElements[i].width, 
                            RenderQueueElements[i].heigh,
                            RenderQueueElements[i].posX,
                            RenderQueueElements[i].posY };
        SDL_RenderFillRect(renderer, &frame);
    }
    SDL_RenderPresent(renderer);
}

void Graphics::PushRenderActor(Actor& a)
{
    RenderQueueSize++;
    RenderQueueElements[RenderQueueSize] = a;
}

void Graphics::PopRenderActor()
{
    RenderQueueSize--;
}