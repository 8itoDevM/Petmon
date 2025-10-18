#pragma once
#include "ScreenManager.h"
#include "Button.h"

class Game{
public:
    Game();
    void Draw();
    void Update();
    void Initialize();

    Camera2D camera;
    ScreenManager scene_manager;
private:
    Button buttons[10];
    bool initialized = false;
};