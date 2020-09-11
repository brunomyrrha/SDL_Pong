#include "headers/Ball.h"

Ball::Ball(SDL_Renderer *renderer) 
{
    this->renderer = renderer;
    ball.posX = WINDOW_WIDTH / 2 - BALL_WIDTH / 2;
    ball.posY = WINDOW_HEIGHT / 2 - BALL_HEIGHT / 2;
    ball.sizeX = BALL_WIDTH;
    ball.sizeY = BALL_HEIGHT;
}

void Ball::Render() 
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect geometry = 
    { 
        (int) ball.posX,
        (int) ball.posY,
        (int) ball.sizeX,
        (int) ball.sizeY
    };
    SDL_RenderDrawRect(renderer, &geometry);
}