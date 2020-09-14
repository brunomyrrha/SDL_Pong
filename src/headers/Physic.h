#pragma once
#include "Actor.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Physic
{
public:
    void MoveBall(Actor& a);
    void InitBallMovement(Actor& a);
    int DidScore(Actor& ball);
    void CalculatePaddleHit(Actor& ball, Actor& computer, Actor& player);
private:
};