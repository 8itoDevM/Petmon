#pragma once
#include "ScreenManager.h"

class Game{
public:
    Game();
    ScreenManager manager;
    void Draw();
    void Update();
private:
};