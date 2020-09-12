#include "headers/AI.h"

void AI::MoveBall(Actor& a)
{
    if(a.state[MOVEMENT_VERTICAL] == UP && a.posY <= a.sizeY) a.state[MOVEMENT_VERTICAL] = DOWN;
    if(a.state[MOVEMENT_VERTICAL] == DOWN && a.posY >= WINDOW_HEIGHT - a.sizeY ) a.state[MOVEMENT_VERTICAL] = UP;
    if(a.state[MOVEMENT_HORIZONTAL] == LEFT && a.posX <= 0) a.state[MOVEMENT_HORIZONTAL] = RIGHT;
    if(a.state[MOVEMENT_HORIZONTAL] == RIGHT && a.posX >= WINDOW_WIDTH - a.sizeX) a.state[MOVEMENT_HORIZONTAL] = LEFT;
}

void InitBallMovement(Actor& a)
{
    srand(time(nullptr));
    int randomNumber = rand() % 2;
    a.state[MOVEMENT_VERTICAL] = static_cast<MoveState>(randomNumber);
    a.state[MOVEMENT_HORIZONTAL] = static_cast<MoveState>(randomNumber + 2);
}