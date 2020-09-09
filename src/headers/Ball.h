#pragma once
#include "Libs.h"

class Ball 
{
public:
    Ball(SDL_Renderer *renderer);
    ~Ball();
    void Render();
private:
    Actor ball;
    SDL_Renderer *renderer;
};