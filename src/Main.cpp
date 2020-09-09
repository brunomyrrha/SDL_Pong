#include "headers/Libs.h"

int main()
{
    Engine* engine = new Engine();
    while(engine->IsRunning()) {
        engine->ProcessInput();
        engine->UpddateStates();
        engine->RenderFrames();
    }
    engine->~Engine();
    return EXIT_SUCCESS;
}