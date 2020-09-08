
#include "headers/Libs.h"

// MARK: - Variables declaration

// MARK: - Internal methods

void MovePlayerUp() {

};

void MovePlayerDown() {

};

// MARK: - Class methods

Controller::Controller() {
    SDL_PumpEvents();
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_UP]) { MovePlayerUp(); };
    if(keyState[SDL_SCANCODE_DOWN]) { MovePlayerDown(); };
}

void Controller::UI() {

}

void Controller::Paddle() {

}