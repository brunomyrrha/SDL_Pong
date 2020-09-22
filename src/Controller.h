#pragma once
#include "Actor.h"
#include "Command.h"

class Controller
{
public:
    Command Press();
    Command Hold();
};