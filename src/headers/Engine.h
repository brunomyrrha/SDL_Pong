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
    bool bIsRunning;
};