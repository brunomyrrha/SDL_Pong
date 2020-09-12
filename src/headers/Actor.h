#pragma once
#include "MoveState.h"

struct Actor {
    float posX, posY, sizeX, sizeY;
    MoveState state = STOP;
};