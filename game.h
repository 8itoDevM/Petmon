#pragma once
#include "ScreenManager.h"

class Game{
public:
    Game();
    void Draw();
    void Update();
    void Initialize();

    ScreenManager scene_manager;
private:
};