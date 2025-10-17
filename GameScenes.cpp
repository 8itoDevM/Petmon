#include "ScreenManager.h"
#include "raylib.h"

Scenes Title(ScreenManager& manager) {
    Scenes s;
    s.Init = []() {
        
    };
    s.Update = [&manager]() {
        if (IsKeyPressed(KEY_ENTER)) manager.ChangeScene("game");
    };
    s.Draw = []() {
        ClearBackground(BLACK);
        DrawText("TITLE - Press Enter", 200, 200, 20, WHITE);
    };

    return s;
}

Scenes Gameplay(ScreenManager& manager) {
    Scenes s;
    s.Init = []() {
        
    };
    s.Update = [&manager]() {
        
    };
    s.Draw = []() {
        ClearBackground(BLACK);
        DrawText("GameScene", 200, 200, 20, WHITE);
    };

    return s;
}