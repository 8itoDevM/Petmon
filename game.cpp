#include "game.h"

Scenes Title(ScreenManager& manager);
Scenes Gameplay(ScreenManager& manager);

Game::Game(){
    

    manager.RegisterScene("menu", Title(manager));
    manager.RegisterScene("game", Gameplay(manager));

    manager.ChangeScene("menu");
};

void Game::Update(){
    manager.Update();
};

void Game::Draw(){
    manager.Draw();
};