#include <math.h>
#include <valarray>

#include "raylib.h"
#include "entities/field.h"
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



    constexpr auto point1 = (Vector2) {200.0f, 150.0f};
    constexpr auto point2 = (Vector2) {600.0f, 150.0f};
    constexpr auto point3 = (Vector2) {600.0f, 450.0f};
    constexpr auto point4 = (Vector2) {200.0f, 450.0f};
    constexpr auto direction1 = (Vector2) {1.0f, 0.0f};
    constexpr auto direction2 = (Vector2) {-1.0f, 0.0f};

    constexpr auto speed = 1.0f;

    auto square1 = Square(
        (Vector2) {300.0f, 300.0f},
        (Vector2) {50.0f, 50.0f},
        direction1,
        BLACK
    );

    auto square2 = Square(
        (Vector2) {500.0f, 300.0f},
        (Vector2) {50.0f, 50.0f},
        direction2,
        RED
    );

    std::vector<Square> squares;

    squares.push_back(square1);
    squares.push_back(square2);

    auto field = Field(point1, point2, point3, point4, squares, speed);


    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsKeyPressed(KEY_SPACE)) {
            field.turnMoving();
        }

        field.update();

        field.draw();

        DrawFPS(10, 10);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
