#include "Game.h"

bool reset = false;

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
    gamePhysic = new Physics();
    gameAI = new AI();
    lastTimeToFrame = 0;
    deltaTime = 0;
    playerScore = 0;
    computerScore = 0;
    InitActors();
    StartNewRound();
}

Game::~Game()
{
    gamePhysic = nullptr;
    gameAI = nullptr;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::ProcessInput()
{
    SDL_Event event;
    Controller control = Controller();
    player.state[MOVEMENT_VERTICAL] = STOP;
    while(SDL_PollEvent(&event))
    {
        control.QuitIfNeeded(event, bIsRunning);
    }
    control.MoveActor(player);
    gamePhysic->MoveBall(ball);
    gamePhysic->CalculatePaddleHit(ball, computer, player);
    gameAI->MoveComputerPaddle(ball, computer);
    ComputeScores();
}

void Game::UpdateStates()
{
    SyncFrameRate();
    switch (ball.state[MOVEMENT_HORIZONTAL])
    {
        case LEFT: ball.posX -= BALL_MOVEMENT_CONSTANT * deltaTime; break;
        case RIGHT: ball.posX += BALL_MOVEMENT_CONSTANT * deltaTime; break;
        default: break;
    }
    switch (ball.state[MOVEMENT_VERTICAL])
    {
        case UP: ball.posY -= BALL_MOVEMENT_CONSTANT * deltaTime; break;
        case DOWN: ball.posY += BALL_MOVEMENT_CONSTANT * deltaTime; break;
        default: break;
    }
    switch (player.state[MOVEMENT_VERTICAL])
    {
        case UP: player.posY -=  PAD_MOVEMENT_CONSTANT * deltaTime; break;
        case DOWN: player.posY += PAD_MOVEMENT_CONSTANT * deltaTime; break;
        default: break;
    }
    switch (computer.state[MOVEMENT_VERTICAL])
    {
        case UP: computer.posY -= PAD_MOVEMENT_CONSTANT * deltaTime; break;
        case DOWN: computer.posY += PAD_MOVEMENT_CONSTANT * deltaTime;break;
        default: break;
    }
    if (reset) {
        StartNewRound();
    }
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

    computer = Actor {
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
    SDL_Rect enemyRect = { (int)computer.posX, (int)computer.posY, (int)computer.sizeX, (int)computer.sizeY };
    SDL_RenderFillRect(renderer, &enemyRect);    
}

void Game::RenderUI()
{

}

void Game::StartNewRound()
{
    player.posY = WINDOW_HEIGHT / 2 - PLAYER_HEIGHT / 2;
    computer.posY = WINDOW_HEIGHT / 2 - PLAYER_HEIGHT / 2;
    ball.posX = WINDOW_WIDTH / 2 - BALL_WIDTH / 2;
    ball.posY = WINDOW_HEIGHT / 2 - BALL_HEIGHT / 2;
    gamePhysic->InitBallMovement(ball);
}

void Game::ComputeScores()
{
    int didScore = gamePhysic->DidScore(ball);
    if (didScore == COMPUTER)
    {
        computerScore++;
        reset = true;
    }
    else if (didScore == PLAYER)
    {
        playerScore++;
        reset = true;
    }
    else
    {
        reset = false;
    }
    //DEBUG GAME STATE
    LOG(playerScore);
    LOG(computerScore);
    if (playerScore + computerScore > 5)
    {
        bIsRunning = false;
    }
}