#include <SDL2/SDL.h>

class TextureAtlas
{
public:
    TextureAtlas(SDL_Texture* atlas);
    void DrawImage(SDL_Renderer* renderer, int x, int y);
private: 
    SDL_Texture* atlas;
    SDL_Rect src, dest;
};