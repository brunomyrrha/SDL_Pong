#pragma once
#include <SDL2/SDL.h>
#include "Actor.h"

class Controller {
public:
    void QuitIfNeeded(SDL_Event& event, bool& bIsRunning);
    void MoveActor(Actor& actor);
};