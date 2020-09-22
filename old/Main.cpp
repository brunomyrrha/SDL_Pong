#include "Game.h"

int main()
{
    Game* g = new Game();
    while(g->IsRunning()) {
        g->ProcessInput();
        g->UpdateStates();
        g->RenderFrames();
    }
    g->~Game();
    return EXIT_SUCCESS;
}