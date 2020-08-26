#include "./headers/Game.h"

Actor player, enemy, ball;
Control_State player_state, enemy_state;


Game::Game() {
    game_is_running = Initialize_SDL();
    last_frame_time = 0;
    player_state = STOP;
    Setup_Ball();
    Setup_Player();
    Setup_Enemy();
}

Game::~Game() {
    Clear();
}

bool Game::Initialize_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Couldn't initialize SDL\n");
        return false;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if(!window) {
        fprintf(stderr, "Error creating window.\n");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        fprintf(stderr, "Error creating renderer.\n");
        return false;
    }
    return true;
}

void Game::Input() {
    Process_Enemy_Input();
    Process_Player_Input();
    Process_UI_Input();
}

void Game::Process_Player_Input() {
    player_state = STOP;
    SDL_PumpEvents();
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_UP] && player.pos_y > 0 ) { player_state = UP; };
    if(keystate[SDL_SCANCODE_DOWN] && player.pos_y <= WINDOW_HEIGHT - player.height) { player_state = DOWN; };
}

void Game::Process_Enemy_Input() {   
    if (enemy.pos_y <= 0) {
        enemy_state = DOWN;
    } else if (enemy.pos_y >= WINDOW_HEIGHT - enemy.height) {
        enemy_state = UP;
    }
}

void Game::Process_UI_Input() {
    SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                game_is_running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    game_is_running = false;
                }    
        }
}

void Game::Update() {
    Sync_Frame_Rate();
    switch(player_state) {
        case UP: player.pos_y -= PAD_MOVEMENT_CONSTANT * delta_time; break;
        case DOWN: player.pos_y += PAD_MOVEMENT_CONSTANT * delta_time; break;
        case STOP: break;
    }
    switch(enemy_state) {
        case UP: enemy.pos_y -= PAD_MOVEMENT_CONSTANT * delta_time; break;
        case DOWN: enemy.pos_y += PAD_MOVEMENT_CONSTANT * delta_time; break;
        case STOP: enemy_state = UP; break;
    }
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    Draw_Player();
    Draw_Enemy();
    Draw_Ball();
    SDL_RenderPresent(renderer);
}

void Game::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Sync_Frame_Rate() {
    int wait_time = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (wait_time > 0 && wait_time <= FRAME_TARGET_TIME) {
        SDL_Delay(wait_time);
    }
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();
}

void Game::Setup_Ball() {
    ball.pos_x = (WINDOW_WIDTH / 2) - (BALL_WIDTH / 2);
    ball.pos_y = (WINDOW_HEIGHT / 2) - (BALL_HEIGHT / 2);
    ball.height = BALL_HEIGHT;
    ball.width = BALL_WIDTH;
}

void Game::Draw_Ball() {
    SDL_Rect ball_rect = {
        (int)ball.pos_x,
        (int)ball.pos_y,
        (int)ball.width,
        (int)ball.height
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);
}

void Game::Setup_Player() {
    player.pos_x = 0;
    player.pos_y = (WINDOW_HEIGHT / 2) - (PLAYER_HEIGHT / 2);
    player.height = PLAYER_HEIGHT;
    player.width = PLAYER_WIDTH;
}

void Game::Draw_Player() {
    SDL_Rect player_rect {
        (int)player.pos_x,
        (int) player.pos_y,
        (int)player.width,
        (int)player.height
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &player_rect);
}

void Game::Setup_Enemy() {
    enemy.pos_x = WINDOW_WIDTH - ENEMY_WIDTH;
    enemy.pos_y = (WINDOW_HEIGHT / 2) - (ENEMY_HEIGHT / 2);
    enemy.width = ENEMY_WIDTH;
    enemy.height = ENEMY_HEIGHT;
}

void Game::Draw_Enemy() {
    SDL_Rect enemy_rect {
        (int)enemy.pos_x,
        (int)enemy.pos_y,
        (int)enemy.width,
        (int)enemy.height        
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &enemy_rect);
}