#include "boid.h"
#include <vector>
#include <iostream>

#define BUILD

int main(void)
{
    // Initialization
  
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input");

    std::vector<boid> boids;
    Vector2 v = {2.0f, 2.0f};
    Color ballColor = DARKBLUE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    #ifdef BUILD
        for(int i = 0; i < 50; i++) {
            Vector2 pos, vel;
            pos.x = GetRandomValue(0, screenWidth);
            pos.y = GetRandomValue(0, screenWidth);
            vel.x = GetRandomValue(0, 4);
            vel.y = GetRandomValue(0, 4);
            boid temp = boid(pos, vel , {0,0}, 5.0);
            boids.push_back(temp);
        }
    #endif
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        

        for(auto &b : boids){
            b.update(boids);
            b.check_bounds(screenWidth, screenHeight);
        }

        #ifdef END
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                boid temp = boid(GetMousePosition(), v, {0.5f, 0.5f}, 10.0f);
                boids.push_back(temp);
            }
        #endif

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(auto &b : boids)
                DrawCircleV(b.pos, b.radius , ballColor);

            DrawText("Click to input a new boid", 10, 10, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}