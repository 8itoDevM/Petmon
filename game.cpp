#include "game.h"
#include "raylib.h"

static int frame_counter = 0;
unsigned char _frame_counter = frame_counter;

Game::Game(){
    scene_manager = ScreenManager();
};

void Game::Initialize()
{
    initialized = true;
    play = Button("Quit", 20, GetFontDefault(), {100, 100}, {40, 20}, { 0, 117, 44, 255 }, { 255, 255, 255, 255 });
}

void Game::Update(){
    if (!initialized) Initialize();
    switch (scene_manager.GetCurrentScene()){ 
        case 0:                                                                 // Intro
            frame_counter++;
            _frame_counter = frame_counter;
            break;
        case 1:                                                                 // Main menu
            if(IsKeyPressed(KEY_S)){
                play.selected = !play.selected;
            }
            play.Update();
            break; 

        default: 
            break;
    }
}

void Game::Draw(){
    switch (scene_manager.GetCurrentScene()){ 
        case 0:                                                                 // Intro
            if(frame_counter <= 2){
                DrawText("Intro", 130, 190, 50, {0, 255, 0, _frame_counter});
            } else{
                scene_manager.ChangeScene(1);
            }
            break;
        case 1:                                                                 // Main menu
            DrawText("Petmon", 10, 10, 60, GREEN);
            play.Draw();
            break; 
        case 2:                                                                 // Game
            DrawText("Game goes here", 80, 100, 50, GREEN);
        default: 
            break;
    }
};

