#include "raylib.h"
#include "game.h"

/*    
    gcc {NOME_DO_ARQUIVO.cpp} -lraylib

    ls -l

    ./a.out

    g++ main.cpp game.cpp ScreenManager.cpp -lraylib -o Petmon

    ./Petmon.out
*/

int main(void)
{
    int screen_width = 480, screen_height = 432;

    Game game = Game();

    InitWindow(screen_width, screen_height, "Petmon");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game.Update();

        BeginDrawing();
            ClearBackground(BLACK);
            game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}