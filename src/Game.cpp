#include "headers/Game.h"

bool Game::InitSDL()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL couldn't be initialized.");
        return false;
    };
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );
    if(!window)
    {
        fprintf(stderr, "Couldn't initialize window.");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        fprintf(stderr, "Couldn't initialize renderer.");
        return false;
    }
    return true;
}

void Game::SyncFrameRate()
{
    int waitTime = FRAME_TARGET_TIME - (SDL_GetTicks() - lastTimeToFrame);
    if (waitTime > 0 && waitTime <= FRAME_TARGET_TIME)
    {
        SDL_Delay(waitTime);
    };
    deltaTime = (SDL_GetTicks() - lastTimeToFrame) / 1000.0f;
    lastTimeToFrame = SDL_GetTicks();
}

Game::Game()
{
    bIsRunning = InitSDL();
    lastTimeToFrame = 0;
    deltaTime = 0;
    InitActors();
    InitAI();
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::ProcessInput()
{
    SDL_Event event;
    Controller control = Controller();
    while(SDL_PollEvent(&event))
    {
        control.QuitIfNeeded(event, bIsRunning);
    }
    control.MoveActor(player);
}

void Game::UpdateStates()
{
    SyncFrameRate();
    if(ball.state[MOVEMENT_HORIZONTAL] == LEFT) ball.posX = ball.posX - BALL_MOVEMENT_CONSTANT * deltaTime;
    if(ball.state[MOVEMENT_HORIZONTAL] == RIGHT) ball.posX = ball.posX + BALL_MOVEMENT_CONSTANT * deltaTime;
    if(ball.state[MOVEMENT_VERTICAL] == UP) ball.posY = ball.posY - BALL_MOVEMENT_CONSTANT * deltaTime;
    if(ball.state[MOVEMENT_VERTICAL] == DOWN) ball.posY = ball.posY + BALL_MOVEMENT_CONSTANT * deltaTime;
}

void Game::RenderFrames()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    RenderUI();
    RenderActors();
    SDL_RenderPresent(renderer);
}

void Game::InitActors()
{
    player = Actor { 
        0,
        WINDOW_HEIGHT / 2 - PLAYER_HEIGHT / 2,
        PLAYER_WIDTH,
        PLAYER_HEIGHT
    };

    enemy = Actor {
        WINDOW_WIDTH - ENEMY_WIDTH,
        WINDOW_HEIGHT / 2 - ENEMY_HEIGHT / 2,
        ENEMY_WIDTH,
        ENEMY_HEIGHT
    };

    ball = Actor {
        WINDOW_WIDTH / 2 - BALL_WIDTH / 2,
        WINDOW_HEIGHT / 2 - BALL_HEIGHT / 2,
        BALL_WIDTH,
        BALL_HEIGHT
    };
}

void Game::RenderActors()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect playerRect = { (int)player.posX, (int)player.posY, (int)player.sizeX, (int)player.sizeY };
    SDL_RenderFillRect(renderer, &playerRect);
    SDL_Rect ballRect = { (int)ball.posX, (int)ball.posY, (int)ball.sizeX, (int)ball.sizeY };
    SDL_RenderFillRect(renderer, &ballRect);
    SDL_Rect enemyRect = { (int)enemy.posX, (int)enemy.posY, (int)enemy.sizeX, (int)enemy.sizeY };
    SDL_RenderFillRect(renderer, &enemyRect);    
}

void Game::RenderUI()
{

}

void Game::InitAI()
{
    artificialIntelligence = new AI();
    artificialIntelligence->InitBallMovement(ball);
    artificialIntelligence->MoveBall(ball);
}