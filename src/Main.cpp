#include "./headers/Game.h"

int main() {
    Game* game = new Game();
    while(game->Is_Running()) {
        game->Input();
        game->Update();
        game->Render();
    }
    return 0;
}