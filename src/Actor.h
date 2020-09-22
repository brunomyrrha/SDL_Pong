#pragma once
#include "State.h"

struct Actor 
{
    int posX, posY, width, heigh;
    int color[3];
    State horizontal, vertical;
};