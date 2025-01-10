#include <math.h>
#include <valarray>

#include "raylib.h"
#include "figures/square.h"

int screenWidth = 800;
int screenHeight = 600;

Vector2 getPointOnCircleWithAngle(const float alpha, const float radius) {
    const float pointX = radius * cos(alpha);
    const float pointY = radius * sin(alpha);

    return (Vector2){pointX, pointY};
}

int main()
{
    InitWindow(screenWidth, screenHeight, "2d light moving");

    SetTargetFPS(60);

    auto square = Square((Vector2){(float) screenWidth / 2, (float) screenHeight / 2} , (Vector2){20.0f, 20.0f}, BLACK);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        square.draw();


        DrawFPS(10, 10);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
