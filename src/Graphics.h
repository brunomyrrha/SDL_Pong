#pragma once
#include <SDL2/SDL.h>
#include "Constants.h"
#include "Actor.h"

class Graphics
{
public:
    Graphics(bool& init);
    ~Graphics();
    void PushRenderActor(Actor& a);
    void PopRenderActor();
    void RenderScene();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

private:
    bool InitSDL();
    int RenderQueueSize;
    Actor RenderQueueElements[0];
};