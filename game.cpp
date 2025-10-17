#include "game.h"
#include "raylib.h"

static int frame_counter = 0;
unsigned char _frame_counter = frame_counter;

Game::Game(){
    scene_manager = ScreenManager();
};

void Game::Update(){
    switch (scene_manager.GetCurrentScene()){ 
        case 0:                                                                 // Intro
            frame_counter++;
            _frame_counter = frame_counter;
            break;
        case 1:                                                                 // Main menu

            break; 

        default: 
            break;
    }
}

void Game::Draw(){
    switch (scene_manager.GetCurrentScene()){ 
        case 0:                                                                 // Intro
            if(frame_counter <= 255){
                DrawText("Intro", 160, 250, 50, {0, 255, 0, _frame_counter});
            } else{
                scene_manager.ChangeScene(1);
            }
            break;
        case 1:                                                                 // Main menu
            DrawText("Petmon", 10, 10, 60, GREEN);
            break; 

        default: 
            break;
    }
};

