#include "AI.h"

void AI::MoveComputerPaddle(Actor& ball, Actor& computer)
{
    
    if (ball.posX < ScreenPortionWidth(5,1) || ball.posX > ScreenPortionWidth(5,3))
    {
        if (ball.posY > computer.posY + computer.sizeY)
        {
            computer.state[MOVEMENT_VERTICAL] = DOWN;
        }
        if (ball.posY < computer.posY)
        {
            computer.state[MOVEMENT_VERTICAL] = UP;
        }
    }
    if (computer.posY >= WINDOW_HEIGHT - computer.sizeY)
    {
        computer.posY = WINDOW_HEIGHT - computer.sizeY - 1;
        computer.state[MOVEMENT_VERTICAL] = STOP;
    }
    if (computer.posY <= 0)
    {
        computer.posY = 1;
        computer.state[MOVEMENT_VERTICAL] = STOP;
    }
}

int AI::ScreenPortionWidth(int divider, int portion)
{
    return (WINDOW_WIDTH * portion) / divider;
}