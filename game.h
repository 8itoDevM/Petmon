#pragma once
#include "ScreenManager.h"
#include "Button.h"

class Game{
public:
    Game();
    void Draw();
    void Update();
    void Initialize();

    ScreenManager scene_manager;
private:
    Button play;
    bool initialized = false;
};