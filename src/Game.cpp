#include "Game.h"

Game::Game()
{
    player = Actor
    {
        0, 0, 10, 10,{255,255,255}, STOP, STOP
    };
    gameGraphics = new Graphics(bGameCanRun);
    gameController = new Controller();
    gameGraphics->PushRenderActor(player);
}

Game::~Game()
{
    gameGraphics = nullptr;
    gameController = nullptr;
}

void Game::Input()
{
    Command press = gameController->Press();
    Command hold = gameController->Hold();

    if (press == cEXIT)
    {
        CloseGame();
    }
    LOG(hold);
}

void Game::Process()
{

}

void Game::Render()
{
    gameGraphics->RenderScene();
}

void Game::CloseGame()
{
    gameGraphics->~Graphics();
    bGameCanRun = false;
}