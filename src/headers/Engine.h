class Engine
{
public:
    Engine();
    ~Engine();
    void ProcessInput();
    void UpddateStates();
    void RenderFrames();
    bool IsRunning() { return bIsRunning; };
private:
    bool InitSDL();
    void SyncFrameRate();
    bool bIsRunning;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int lastTimeToFrame;
    int deltaTime;
};