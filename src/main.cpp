#include "core.h"
#include <vector>
#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input");

    std::vector<ball> balls;
    Vector2 v = {2.0f, 2.0f};
    Color ballColor = DARKBLUE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        for(auto &b : balls){
            b.update();
            b.check_bounds(screenWidth, screenHeight);
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            ball temp = ball(GetMousePosition(), v, 10.0f);
            balls.push_back(temp);
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(auto &b : balls)
                DrawCircleV(b.pos, 10 , ballColor);

            DrawText("Click to input a new ball", 10, 10, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}