#pragma once
#include "Graphics.h"
#include "Controller.h"

class Game 
{
public:
    Game();
    ~Game();
    void Input();
    void Process();
    void Render();
    bool IsRunning() { return bGameCanRun; }
private:
    Graphics* gameGraphics;
    Controller* gameController;
    bool bGameCanRun;
    Actor  player;
private:
    void CloseGame();
};
