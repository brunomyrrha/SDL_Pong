#pragma once
#include "Libs.h"

class Ball 
{
public:
    Ball(SDL_Renderer *renderer);
    void Render();
private:
    Actor ball;
    SDL_Renderer *renderer;
};