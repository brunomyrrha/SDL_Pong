class Controller {
public:
    void QuitIfNeeded(SDL_Event& event, bool& bIsRunning);
    void MovePlayerPaddle();
private:
    void MovePlayerUp();
    void MovePlayerDown();
};