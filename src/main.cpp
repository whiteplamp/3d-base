#include <math.h>
#include <valarray>

#include "raylib.h"
#include "figures/circle.h"

int screenWidth = 800;
int screenHeight = 600;

Vector2 getPointOnCircleWithAngle(const float alpha, const float radius) {
    const float pointX = radius * cos(alpha);
    const float pointY = radius * sin(alpha);

    return (Vector2){pointX, pointY};
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Sphere");

    float alpha = 0.0f;

    constexpr float ALPHA_STEP = 0.01f;

    float cameraRadius = 10.0f;

    Vector2 cameraPos = getPointOnCircleWithAngle(alpha, cameraRadius);
    Camera camera = { 0 };

    camera.position = (Vector3){ cameraPos.x, 5.0f, cameraPos.y };

    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawSphereWires((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 16, 16, LIME);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawFPS(10, 10);

        EndDrawing();
        alpha += ALPHA_STEP;
        auto point = getPointOnCircleWithAngle(alpha, cameraRadius);
        camera.position.x = point.x;
        camera.position.z = point.y;
    }

    CloseWindow();

    return 0;
}
