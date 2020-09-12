#pragma once
#include <SDL2/SDL.h>
#include "Constants.h"
#include "Actor.h"

class Game
{
public:
    Game();
    ~Game();
    void ProcessInput();
    void UpddateStates();
    void RenderFrames();
    bool IsRunning() { return bIsRunning; };
private:
    bool InitSDL();
    void SyncFrameRate();
    bool bIsRunning;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int lastTimeToFrame;
    int deltaTime;
    Actor player, ball, enemy;
    void InitActors();
    void RenderActors();
    void RenderUI();
};