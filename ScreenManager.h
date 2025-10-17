#pragma once

class ScreenManager{
public: 
    ScreenManager();
    void ChangeScene(int scene);
    void DrawScene(int scene);
    void UpdateScene(int scene);
    int GetCurrentScene();
private:
    int scene_id;
};