#include "headers/Libs.h"

// MARK: - Variables declaration

SDL_Renderer* renderer;
SDL_Window *window;
int lastTimeToFrame = 0;
int deltaTime = 0;

// MARK: - Internal methods

bool InitSDL()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL couldn't be initialized.");
        return false;
    };
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );
    if(!window)
    {
        fprintf(stderr, "Couldn't initialize window.");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        fprintf(stderr, "Couldn't initialize renderer.");
        return false;
    }
    return true;
}

void SyncFrameRate()
{
    int waitTime = FRAME_TARGET_TIME - (SDL_GetTicks() - lastTimeToFrame);
    if (waitTime > 0 && waitTime <= FRAME_TARGET_TIME)
    {
        SDL_Delay(waitTime);
    };
    deltaTime = (SDL_GetTicks() - lastTimeToFrame) / 1000.0f;
    lastTimeToFrame = SDL_GetTicks();
};

// MARK: - Class methods

Engine::Engine()
{
    bIsRunning = InitSDL();
    lastTimeToFrame = 0;
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::ProcessInput()
{
    
}

void Engine::UpddateStates()
{
    SyncFrameRate();
}

void Engine::RenderFrames()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

