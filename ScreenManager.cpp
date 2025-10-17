#include "ScreenManager.h"
#include "raylib.h"

ScreenManager::ScreenManager(){
    scene_id = 0;
    scenes[0];
}

void ScreenManager::ChangeScene(int scene){
    scenes[scene];
    scene_id = scene;
}

int ScreenManager::GetCurrentScene()
{
    return scene_id;
}
