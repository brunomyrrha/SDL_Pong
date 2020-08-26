#include <SDL2/SDL.h>
#include <iostream>
#include "Constants.h"
#include "Control_State.h"
#include "Actor.h"

class Game {
public:
    Game();
    ~Game();
    void Input();
    void Update();
    void Render();
    bool Is_Running() { return game_is_running; };
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool game_is_running;
    int last_frame_time;
    float delta_time;
    bool Initialize_SDL();
    void Clear();
    void Sync_Frame_Rate();
    void Setup_Ball();
    void Draw_Ball();
    void Setup_Player();
    void Draw_Player();
    void Setup_Enemy();
    void Draw_Enemy();
    void Process_Player_Input();
    void Process_Enemy_Input();
    void Process_UI_Input();

};