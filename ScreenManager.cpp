#include "ScreenManager.h"

void ScreenManager::RegisterScene(const std::string &name, Scenes scene)
{
    scenes[name] = scene;
}

void ScreenManager::ChangeScene(const std::string &name)
{
    current_scene = &scenes[name];
    if (current_scene->Init) current_scene->Init();
}

void ScreenManager::Update()
{
    if (current_scene && current_scene->Update)
        current_scene->Update();
}

void ScreenManager::Draw()
{
    if (current_scene && current_scene->Update)
        current_scene->Draw();
}
