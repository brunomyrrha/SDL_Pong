#include "Controller.h"
#include <SDL2/SDL_events.h>

Command Controller::Press() 
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: return cEXIT;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) return cEXIT;
        }
    }
    return cNONE;
}

Command Controller::Hold()
{
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W]) return cUP;
    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S]) return cDOWN;
    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]) return cLEFT;
    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]) return cRIGHT;
    return cNONE;
}