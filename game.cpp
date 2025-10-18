#include "game.h"
#include "raylib.h"
#include <math.h>

static int frame_counter = 0;
unsigned char _frame_counter = frame_counter;

Rectangle placeholder_player = { 400, 280, 40, 40 };

Game::Game(){
    scene_manager = ScreenManager();
};

void Game::Initialize()
{
    initialized = true;
    buttons[0] = Button("Play", 20, GetFontDefault(), {10, 80}, {40, 20}, { 0, 117, 44, 255 }, { 255, 255, 255, 255 });
    buttons[1] = Button("Quit", 20, GetFontDefault(), {10, 120}, {40, 20}, { 0, 117, 44, 255 }, { 255, 255, 255, 255 });
    camera = { 0 };
    camera.target = (Vector2){ placeholder_player.x + 20.0f, placeholder_player.y + 20.0f };
    camera.offset = (Vector2){ 480/2.0f, 432/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
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
                buttons[0].selected = !buttons[0].selected;
            }
            if(buttons[0].Click()){
                scene_manager.ChangeScene(2);
            }
            buttons[0].Update();
            break;
        case 2:
            if (IsKeyDown(KEY_RIGHT)) placeholder_player.x += 2;
            else if (IsKeyDown(KEY_LEFT)) placeholder_player.x -= 2;

            if (IsKeyDown(KEY_DOWN)) placeholder_player.y += 2;
            else if (IsKeyDown(KEY_UP)) placeholder_player.y -= 2;

            camera.target = (Vector2){ placeholder_player.x + 20, placeholder_player.y + 20 };

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
            buttons[0].Draw();
            break; 
        case 2:                                                                 // Game
            BeginMode2D(camera);
                DrawRectangleRec({20, 25, 10, 10}, WHITE);
                DrawRectangleRec(placeholder_player, RED);
            EndMode2D();

            
        default: 
            break;
    }
};

