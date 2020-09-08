// #include "./headers/Game.h"

// Actor player, enemy, ball;
// Control_State player_state, enemy_state, ball_state[2];


// Game::Game() {
//     game_is_running = true;
//     last_frame_time = 0;
//     player_state = STOP;
//     enemy_state = UP;
//     ball_state[BALL_PAD_HORIZONTAL] = LEFT;
//     ball_state[BALL_PAD_VERTICAL] = UP;
//     Setup_Ball();
//     Setup_Player();
//     Setup_Enemy();
// }

// Game::~Game() {
//     Clear();
// }



// void Game::Input() {
//     Process_Enemy_Input();
//     Process_Player_Input();
//     Process_UI_Input();
//     Process_Ball_Movement();
// }

// void Game::Process_Player_Input() {
//     player_state = STOP;
//     SDL_PumpEvents();
//     const Uint8* keystate = SDL_GetKeyboardState(NULL);
//     if(keystate[SDL_SCANCODE_UP] && player.pos_y > 0 ) { player_state = UP; };
//     if(keystate[SDL_SCANCODE_DOWN] && player.pos_y <= WINDOW_HEIGHT - player.height) { player_state = DOWN; };
// }

// void Game::Process_Enemy_Input() {   
//     if (enemy.pos_y <= 0) {
//         enemy_state = DOWN;
//     } else if (enemy.pos_y >= WINDOW_HEIGHT - enemy.height) {
//         enemy_state = UP;
//     }
// }

// void Game::Process_Ball_Movement() {
//     if (ball.pos_y < 0) {
//         ball_state[BALL_PAD_VERTICAL] = DOWN;
//     }
//     if (ball.pos_y > (WINDOW_HEIGHT - ball.height)) {
//         ball_state[BALL_PAD_VERTICAL] = UP;
//     }
//     if (ball.pos_x < player.width) {
//         if (ball.pos_y > player.pos_y && ball.pos_y < (player.pos_y + player.height)) {
//             ball_state[BALL_PAD_HORIZONTAL] = RIGHT;
//             std::cout<<"HIT PLAYER"<<std::endl;
//         }
//     }
//     if (ball.pos_x < 0) {
//         ball_state[BALL_PAD_HORIZONTAL] = RIGHT;
//         std::cout<<"ENEMY SCORE"<<std::endl;
//     }
//     if (ball.pos_x > (WINDOW_WIDTH - ball.width - enemy.width)) {
//         if (ball.pos_y > enemy.pos_y && ball.pos_y < (enemy.pos_y + enemy.height)) {
//             ball_state[BALL_PAD_HORIZONTAL] = LEFT;
//             std::cout<<"HIT ENEMY"<<std::endl;
//         }
//     }
//     if (ball.pos_x > (WINDOW_WIDTH - ball.width)) {
//         ball_state[BALL_PAD_HORIZONTAL] = LEFT;
//         std::cout<<"PLAYER SCORE"<<std::endl;
//     }
// }

// void Game::Process_UI_Input() {
//     SDL_Event event;
//         SDL_PollEvent(&event);
//         switch(event.type) {
//             case SDL_QUIT:
//                 game_is_running = false;
//                 break;
//             case SDL_KEYDOWN:
//                 if(event.key.keysym.sym == SDLK_ESCAPE) {
//                     game_is_running = false;
//                 }    
//         }
// }

// void Game::Update() {
//     Sync_Frame_Rate();
//     switch(player_state) {
//         case UP: player.pos_y -= PAD_MOVEMENT_CONSTANT * delta_time; break;
//         case DOWN: player.pos_y += PAD_MOVEMENT_CONSTANT * delta_time; break;
//         default: break;
//     }
//     switch(enemy_state) {
//         case UP: enemy.pos_y -= PAD_MOVEMENT_CONSTANT * delta_time; break;
//         case DOWN: enemy.pos_y += PAD_MOVEMENT_CONSTANT * delta_time; break;
//         default: break;
//     }
//     switch(ball_state[BALL_PAD_VERTICAL]) {
//         case UP: ball.pos_y -= BALL_MOVEMENT_CONSTANT * delta_time; break;
//         case DOWN: ball.pos_y += BALL_MOVEMENT_CONSTANT * delta_time; break; 
//         default: break;
//     }
//     switch(ball_state[BALL_PAD_HORIZONTAL]) {
//         case LEFT: ball.pos_x -= BALL_MOVEMENT_CONSTANT * delta_time; break;
//         case RIGHT: ball.pos_x += BALL_MOVEMENT_CONSTANT * delta_time; break;
//         default: break;
//     }
// }

// void Game::Render() {
//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//     SDL_RenderClear(renderer);
//     Draw_Half_Field();
//     Draw_Player();
//     Draw_Enemy();
//     Draw_Ball();
//     SDL_RenderPresent(renderer);
// }

// void Game::Clear() {
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }

// void Game::Sync_Frame_Rate() {
//     int wait_time = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
//     if (wait_time > 0 && wait_time <= FRAME_TARGET_TIME) {
//         SDL_Delay(wait_time);
//     }
//     delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
//     last_frame_time = SDL_GetTicks();
// }

// void Game::Setup_Ball() {
//     ball.pos_x = (WINDOW_WIDTH / 2) - (BALL_WIDTH / 2);
//     ball.pos_y = (WINDOW_HEIGHT / 2) - (BALL_HEIGHT / 2);
//     ball.height = BALL_HEIGHT;
//     ball.width = BALL_WIDTH;
// }

// void Game::Draw_Ball() {
//     SDL_Rect ball_rect = {
//         (int)ball.pos_x,
//         (int)ball.pos_y,
//         (int)ball.width,
//         (int)ball.height
//     };
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(renderer, &ball_rect);
// }

// void Game::Setup_Player() {
//     player.pos_x = 0;
//     player.pos_y = int((WINDOW_HEIGHT / 2) - (PLAYER_HEIGHT / 2));
//     player.height = PLAYER_HEIGHT;
//     player.width = PLAYER_WIDTH;
// }

// void Game::Draw_Player() {
//     SDL_Rect player_rect {
//         (int)player.pos_x,
//         (int) player.pos_y,
//         (int)player.width,
//         (int)player.height
//     };
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(renderer, &player_rect);
// }

// void Game::Setup_Enemy() {
//     enemy.pos_x = WINDOW_WIDTH - ENEMY_WIDTH;
//     enemy.pos_y = (WINDOW_HEIGHT / 2) - (ENEMY_HEIGHT / 2);
//     enemy.width = ENEMY_WIDTH;
//     enemy.height = ENEMY_HEIGHT;
// }

// void Game::Draw_Enemy() {
//     SDL_Rect enemy_rect {
//         (int)enemy.pos_x,
//         (int)enemy.pos_y,
//         (int)enemy.width,
//         (int)enemy.height        
//     };
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(renderer, &enemy_rect);
// }

// void Game::Draw_Half_Field() {
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     int x_axis = WINDOW_WIDTH / 2;
//     int y_points[2];
//     for (int i = 0; i < MAX_DOTS_LINE; i++) {
//         for (int j = 0; j < 2; j++) {
//             y_points[j] = WINDOW_HEIGHT / MAX_DOTS_LINE * i;
//         }
//         SDL_RenderDrawLine(renderer, x_axis, y_points[0], x_axis, y_points[1]);   
//     }
// }