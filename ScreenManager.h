#pragma once
#include "Scenes.h"
#include <map>
#include <string>

class ScreenManager{
public:
    void RegisterScene(const std::string& name, Scenes scene);
    void ChangeScene(const std::string& name);
    void Update();
    void Draw();
private:
    std::map<std::string, Scenes> scenes;
    Scenes* current_scene = nullptr;
};