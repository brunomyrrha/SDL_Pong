#include "headers/Game.h"

int main()
{
    Game* g = new Game();
    while(g->IsRunning()) {
        g->ProcessInput();
        g->UpddateStates();
        g->RenderFrames();
    }
    g->~Game();
    return EXIT_SUCCESS;
}