#include <iostream>
#include <math.h>
#include <memory>
#include <valarray>
#include <vector>

#include "button.h"
#include "raylib.h"
#include "screen.h"
#include "figures/circle.h"
#include "figures/cube.h"
#include "viewports/main_viewport.h"
#include "viewports/menu_viewport.h"

int screenWidth = 1600;
int screenHeight = 900;

Vector2 getPointOnCircleWithAngle(const float alpha, const float radius) {
    const float pointX = radius * cos(alpha);
    const float pointY = radius * sin(alpha);

    return (Vector2){pointX, pointY};
}

int main()
{
    InitWindow(screenWidth, screenHeight, "3D redactor");

    Camera viewPortCamera  = { 0 };

    viewPortCamera.position = (Vector3){ 100.0f, 100.0f, 105.0f };

    viewPortCamera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    viewPortCamera.up = (Vector3){ 0.0f, 0.1f, 0.0f };
    viewPortCamera.fovy = 60.0f;
    viewPortCamera.projection = CAMERA_PERSPECTIVE;

    auto cube = Cube((Vector3) {0.0f, 25.0f, 0.0f}, 50.0f);

    auto font = LoadFontEx("../resources/VipBold.otf", 28, 0, NULL);


    auto buttonStart = Button(
        (Vector2) {100.0f, 100.0f},
        (Vector2) {200.0f, 80.0f},
        "Press me",
        BLUE,
        DARKBLUE,
        font,
        28
    );

    SetTargetFPS(60);

    auto viewport = std::make_unique<MainViewport>(
        (Vector2) {0, 0.0f},
        (Vector2) {(float)screenWidth, (float)screenHeight},
        viewPortCamera,
        RAYWHITE,
        "3D",
        cube
    );

    /*auto menu = std::make_unique<MenuViewport>(
        (Vector2) {0.0f, 0.0f},
        (Vector2) {(float)screenWidth / 2.0f, (float)screenHeight},
        viewPortCamera,
        RAYWHITE,
        "2D",
        buttonStart
    );*/

    std::vector<std::unique_ptr<BaseViewport>> viewports;

    // viewports.push_back(std::move(menu));
    viewports.push_back(std::move(viewport));

    auto screen = Screen(viewports);

    while (!WindowShouldClose())
    {
        screen.draw();

    }
    CloseWindow();

    return 0;
}
