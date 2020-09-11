#include "headers/Libs.h"

void Controller::QuitIfNeeded(SDL_Event& event, bool& bIsRunning) 
{
    switch(event.type) {
        case SDL_QUIT:
            bIsRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) bIsRunning = false;
            break;
    }
}

void Controller::MovePlayerPaddle() 
{
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_UP]) { MovePlayerUp(); };
    if(keyState[SDL_SCANCODE_DOWN]) { MovePlayerDown(); };
}

void Controller::MovePlayerUp() 
{
    fprintf(stderr, "UP");
}

void Controller::MovePlayerDown() 
{
    fprintf(stderr, "DOWN");
}
