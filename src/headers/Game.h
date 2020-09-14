#pragma once
#include <SDL2/SDL.h>
#include "Constants.h"
#include "Actor.h"
#include "Physic.h"
#include "Controller.h"

class Game {
public:
    Game();
    ~Game();
    void ProcessInput();
    void UpdateStates();
    void RenderFrames();
    bool IsRunning() { return bIsRunning; };
private:
    Actor player, ball, computer;
    Physic* gamePhysic;
    SDL_Renderer* renderer;
    SDL_Window* window;
    int lastTimeToFrame;
    int playerScore;
    int computerScore;
    float deltaTime;
    bool bIsRunning;
    bool InitSDL();
    void SyncFrameRate();
    void InitActors();
    void RenderActors();
    void RenderUI();
    void StartNewRound();
    void ComputeScores();
};