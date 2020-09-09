#include "headers/Libs.h"

// MARK: - Internal methods

bool Engine::InitSDL()
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
        0
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

void Engine::SyncFrameRate()
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
    deltaTime = 0;
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::ProcessInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            bIsRunning = false;
        }
        if (e.type == SDL_KEYDOWN){
            bIsRunning = false;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN){
            bIsRunning = false;
        }
    }
}

void Engine::UpddateStates()
{
    SyncFrameRate();
}

void Engine::RenderFrames()
{
    Ball b = Ball(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    b.Render();
    SDL_RenderPresent(renderer);
}

