#include "Physics.h"

void Physics::MoveBall(Actor& a)
{
    if (a.state[MOVEMENT_VERTICAL] == UP && a.posY <= 0) a.state[MOVEMENT_VERTICAL] = DOWN;
    if (a.state[MOVEMENT_VERTICAL] == DOWN && a.posY >= WINDOW_HEIGHT - a.sizeY ) a.state[MOVEMENT_VERTICAL] = UP;
    if (a.state[MOVEMENT_HORIZONTAL] == LEFT && a.posX <= 0) a.state[MOVEMENT_HORIZONTAL] = RIGHT;
    if (a.state[MOVEMENT_HORIZONTAL] == RIGHT && a.posX >= WINDOW_WIDTH - a.sizeX) a.state[MOVEMENT_HORIZONTAL] = LEFT;
}

void Physics::InitBallMovement(Actor& a)
{
    srand(time(nullptr));
    a.state[MOVEMENT_VERTICAL] = static_cast<MoveState>(rand() % 2);
    a.state[MOVEMENT_HORIZONTAL] = static_cast<MoveState>(rand() % 2 + 2);
}

int Physics::DidScore(Actor& ball)
{
    if (ball.posX >= WINDOW_WIDTH - ball.sizeX) return PLAYER;
    if (ball.posX <= 0) return COMPUTER;
    return 0;
}

void Physics::CalculatePaddleHit(Actor& ball, Actor& computer, Actor& player)
{
    if (ball.posX >= WINDOW_WIDTH - ball.sizeX - computer.sizeX)
    {
        if (ball.posY >= computer.posY && ball.posY <= computer.posY + computer.sizeY - ball.sizeY) ball.state[MOVEMENT_HORIZONTAL] = LEFT;
    }
    if (ball.posX <= player.sizeX)
    {
        if (ball.posY >= player.posY && ball.posY <= player.posY + player.sizeY - ball.sizeY) ball.state[MOVEMENT_HORIZONTAL] = RIGHT;
    }
}