#include "Controller.h"

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

void Controller::MoveActor(Actor& actor) 
{
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_UP] && actor.posY > 0) actor.state[MOVEMENT_VERTICAL] = UP;
    if(keyState[SDL_SCANCODE_DOWN] && actor.posY < WINDOW_HEIGHT - actor.sizeY) actor.state[MOVEMENT_VERTICAL] = DOWN;
}