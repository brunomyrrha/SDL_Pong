#include "Game.h"

int main() {
    Game* g = new Game();
    while (g->IsRunning())
    {
        g->Input();
        g->Process();
        g->Render();
    }
    return 0;
}