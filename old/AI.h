#pragma once
#include "Actor.h"
#include "Constants.h"

class AI
{
public:
    void MoveComputerPaddle(Actor& ball, Actor& computer);
private:
    int ScreenPortionWidth(int divider, int portion);
};